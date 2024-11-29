#include <iostream>
#include <random>
#include <vector>
#include <list>
#include <map>
#include <deque>
#include "MemoryPoolAllocator.tpp"

// include header of your allocator here
template<class T>
using MyAllocator = MemoryPoolAllocator<T>;

using Point2D = std::pair<int, int>;

const int TestSize = 10000;
const int PickSize = 1000;

int main()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, TestSize);

    std::cout << "Testing vector creation" << std::endl;
    using IntVec = std::vector<int, MyAllocator<int>>;
    std::vector<IntVec, MyAllocator<IntVec>> vecints(TestSize);
    for (int i = 0; i < TestSize; i++)
        vecints[i].resize(dis(gen));

    using PointVec = std::vector<Point2D, MyAllocator<Point2D>>;
    std::vector<PointVec, MyAllocator<PointVec>> vecpts(TestSize);
    for (int i = 0; i < TestSize; i++)
        vecpts[i].resize(dis(gen));

    std::cout << "Testing vector resize" << std::endl;
    for (int i = 0; i < PickSize; i++) {
        int idx = dis(gen) - 1;
        int size = dis(gen);
        vecints[idx].resize(size);
        vecpts[idx].resize(size);
    }

    std::cout << "Testing vector assignment" << std::endl;
    {
        int val = 10;
        int idx1 = dis(gen) - 1;
        int idx2 = vecints[idx1].size() / 2;
        vecints[idx1][idx2] = val;
        if (vecints[idx1][idx2] == val)
            std::cout << "correct assignment in vecints: " << idx1 << std::endl;
        else
            std::cout << "incorrect assignment in vecints: " << idx1 << std::endl;
    }
    {
        Point2D val(11, 15);
        int idx1 = dis(gen) - 1;
        int idx2 = vecpts[idx1].size() / 2;
        vecpts[idx1][idx2] = val;
        if (vecpts[idx1][idx2] == val)
            std::cout << "correct assignment in vecpts: " << idx1 << std::endl;
        else
            std::cout << "incorrect assignment in vecpts: " << idx1 << std::endl;
    }

    std::cout << "Testing vector destruction" << std::endl;
    vecints.clear();
    vecpts.clear();

    std::cout << "Testing map creation and insertion" << std::endl;
    using IntMap = std::map<int, int, std::less<int>, MyAllocator<std::pair<const int, int>>>;
    IntMap* mapints = new IntMap();
    using PointMap = std::map<int, Point2D, std::less<int>, MyAllocator<std::pair<const int, Point2D>>>;
    PointMap* mappts = new PointMap();
    for (int i = 0; i < TestSize; i++) {
        mapints->insert({ i, dis(gen) });
        mappts->insert({ i, {dis(gen), dis(gen)} });
    }

    std::cout << "Testing map assignment" << std::endl;
    {
        int val = 10;
        int idx = dis(gen) - 1;
        (*mapints)[idx] = val;
        if ((*mapints)[idx] == val)
            std::cout << "correct assignment in mapints: " << idx << std::endl;
        else
            std::cout << "incorrect assignment in mapints: " << idx << std::endl;
    }
    {
        Point2D val(24, 65676);
        int idx = dis(gen) - 1;
        (*mappts)[idx] = val;
        if ((*mappts)[idx] == val)
            std::cout << "correct assignment in mappts: " << idx << std::endl;
        else
            std::cout << "incorrect assignment in mappts: " << idx << std::endl;
    }

    std::cout << "Testing map destruction" << std::endl;
    delete mapints;
    delete mappts;

    std::cout << "Testing complete" << std::endl;

    return 0;
}
