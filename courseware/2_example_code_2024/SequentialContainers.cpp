#include <iostream>
#include <array>
#include <vector>
#include <deque>
#include <forward_list>
#include <list>

int main() {
    // 1. array example: fixed-size static array
    std::array<int, 5> arr = {1, 2, 3, 4, 5};
    std::cout << "Array: ";
    for (int i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << " ";  // Output array elements
    }
    std::cout << std::endl;

    // 2. vector example: dynamic-size array
    std::vector<int> vec = {1, 2, 3};
    vec.push_back(4);  // Dynamically adding elements
    vec.push_back(5);
    std::cout << "Vector (after push_back): ";
    for (int i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";  // Output vector elements
    }
    std::cout << std::endl;

    // 3. deque example: double-ended queue
    std::deque<int> deq = {2, 3, 4};
    deq.push_front(1);  // Insert at the front
    deq.push_back(5);   // Insert at the back
    std::cout << "Deque (after push_front and push_back): ";
    for (int i = 0; i < deq.size(); ++i) {
        std::cout << deq[i] << " ";  // Output deque elements
    }
    std::cout << std::endl;

    // 4. forward_list example: singly-linked list
    std::forward_list<int> flist = {2, 3, 4};
    flist.push_front(1);  // Insert at the front
    std::cout << "Forward_list (after push_front): ";
    for (int num : flist) {
        std::cout << num << " ";  // Output forward_list elements
    }
    std::cout << std::endl;

    // 5. list example: doubly-linked list
    std::list<int> lst = {2, 3, 4};
    lst.push_front(1);  // Insert at the front
    lst.push_back(5);   // Insert at the back
    std::cout << "List (after push_front and push_back): ";
    for (int num : lst) {
        std::cout << num << " ";  // Output list elements
    }
    std::cout << std::endl;

    // Difference between vector and linked lists (forward_list and list)
    std::cout << "\n=== Difference between vector and linked lists ===\n";

    // Inserting 1000 elements in the middle of vector using index
    std::cout << "Inserting 1000 elements in the middle of vector...\n";
    size_t middle_index = vec.size() / 2;  // Start from the middle index
    for (int i = 0; i < 10000000; ++i) {
        vec.insert(vec.begin() + middle_index, i);  // Insert at the middle each time
        middle_index++;  // Increment middle index to account for newly inserted element
    }
    std::cout << "Vector size after insertion: " << vec.size() << std::endl;

    std::cout << "Inserting 1000 elements in the middle of list...\n";
    auto list_it = lst.begin();
    std::advance(list_it, lst.size() / 2);  // Moving iterator to the middle of the list
    for (int i = 0; i < 10000000; ++i) {
        lst.insert(list_it, i);  // Inserting elements in the middle of a list, more efficient
    }
    std::cout << "List size after insertion: " << lst.size() << std::endl;

    return 0;
}
