#include <iostream>
#include <set>
#include <string>

int main() {
    // Example of std::set: stores unique elements
    std::set<std::string> mySet;

    // Inserting elements into the set
    mySet.insert("apple");
    mySet.insert("banana");
    mySet.insert("orange");
    mySet.insert("banana");  // Duplicate entry, will be ignored

    std::cout << "Elements in set (unique elements only): ";
    for (const auto& elem : mySet) {
        std::cout << elem << " ";  // Output: apple banana orange
    }
    std::cout << std::endl;

    // Example of std::multiset: allows duplicate elements
    std::multiset<std::string> myMultiset;

    // Inserting elements into the multiset
    myMultiset.insert("apple");
    myMultiset.insert("banana");
    myMultiset.insert("orange");
    myMultiset.insert("banana");  // Duplicate entry allowed

    std::cout << "Elements in multiset (allows duplicates): ";
    for (const auto& elem : myMultiset) {
        std::cout << elem << " ";  // Output: apple banana banana orange
    }
    std::cout << std::endl;

    // Count occurrences in multiset
    std::cout << "Count of 'banana' in multiset: " << myMultiset.count("banana") << std::endl;  // Output: 2

    return 0;
}
