#include <iostream>
#include <vector>
#include <algorithm>  // std::find

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // find element 3
    auto it = std::find(vec.begin(), vec.end(), 3);

    if (it != vec.end()) {
        std::cout << "Element found at position: " << std::distance(vec.begin(), it) << std::endl;
    } else {
        std::cout << "Element not found." << std::endl;
    }

    return 0;
}