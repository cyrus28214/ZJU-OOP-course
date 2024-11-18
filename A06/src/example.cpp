#include <iostream>
#include "Vector.h"

/**
 * @brief Demonstrates the usage of the custom `Vector` class.
 */
int main() {
    std::cout << "==== Vector Class Use Cases ====" << std::endl;

    // 1. Default Constructor
    std::cout << "\n--- Example 1: Default Constructor ---" << std::endl;
    Vector<int> vec1;
    std::cout << "Vector initialized. Size: " << vec1.size() << ", Empty: " << (vec1.empty() ? "Yes" : "No") << std::endl;

    // 2. Constructor with Size
    std::cout << "\n--- Example 2: Constructor with Size ---" << std::endl;
    Vector<int> vec2(5); // Creates a vector with space for 5 elements
    std::cout << "Vector created with size 5. Initializing elements..." << std::endl;
    for (int i = 0; i < vec2.size(); ++i) {
        vec2[i] = i + 1; // Assign values to each element
        std::cout << "vec2[" << i << "] = " << vec2[i] << std::endl;
    }

    // 3. push_back and Dynamic Resizing
    std::cout << "\n--- Example 3: Dynamic Resizing with push_back ---" << std::endl;
    Vector<int> vec3;
    std::cout << "Adding elements to vec3 using push_back:" << std::endl;
    for (int i = 1; i <= 10; ++i) {
        vec3.push_back(i * 10);
        std::cout << "Added " << i * 10 << ", New Size: " << vec3.size() << std::endl;
    }

    // Accessing elements
    std::cout << "Elements in vec3: ";
    for (int i = 0; i < vec3.size(); ++i) {
        std::cout << vec3[i] << " ";
    }
    std::cout << std::endl;

    // 4. Using at() for bounds-checked access
    std::cout << "\n--- Example 4: Bounds-Checked Access with at() ---" << std::endl;
    try {
        std::cout << "Accessing vec3.at(5): " << vec3.at(5) << std::endl;
        std::cout << "Accessing vec3.at(20) (out of bounds): ";
        std::cout << vec3.at(20) << std::endl; // This will throw an exception
    }
    catch (const std::out_of_range& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    // 5. Copy Constructor
    std::cout << "\n--- Example 5: Copy Constructor ---" << std::endl;
    Vector<int> vec4 = vec3; // Create a copy of vec3
    std::cout << "Created vec4 as a copy of vec3. Elements in vec4: ";
    for (int i = 0; i < vec4.size(); ++i) {
        std::cout << vec4[i] << " ";
    }
    std::cout << std::endl;

    // Modifying vec4 and verifying independence
    vec4[0] = 999;
    std::cout << "Modified vec4[0] = 999. Checking vec3 and vec4 independence..." << std::endl;
    std::cout << "vec3[0]: " << vec3[0] << ", vec4[0]: " << vec4[0] << std::endl;

    // 6. clear() and empty()
    std::cout << "\n--- Example 6: Clearing a Vector ---" << std::endl;
    std::cout << "Clearing vec4..." << std::endl;
    vec4.clear();
    std::cout << "vec4 cleared. Size: " << vec4.size() << ", Empty: " << (vec4.empty() ? "Yes" : "No") << std::endl;

    // 7. Custom Data Types
    std::cout << "\n--- Example 7: Using Custom Data Types ---" << std::endl;
    struct Point {
        int x, y;
        Point() : x(0), y(0) {} // must have default constructor for Vector to work
        Point(int x, int y) : x(x), y(y) {}
    };

    Vector<Point> pointVec;
    pointVec.push_back(Point(1, 2));
    pointVec.push_back(Point(3, 4));
    std::cout << "Added custom Point objects to the vector." << std::endl;
    for (int i = 0; i < pointVec.size(); ++i) {
        std::cout << "Point " << i << ": (" << pointVec[i].x << ", " << pointVec[i].y << ")" << std::endl;
    }

    // 8. Large-Scale Insertion
    std::cout << "\n--- Example 8: Handling Large-Scale Data ---" << std::endl;
    Vector<int> largeVec;
    const int num_elements = 100000;
    std::cout << "Inserting " << num_elements << " elements into a vector..." << std::endl;
    for (int i = 0; i < num_elements; ++i) {
        largeVec.push_back(i);
    }
    std::cout << "Inserted " << largeVec.size() << " elements successfully!" << std::endl;

    // Display some elements from the large vector
    std::cout << "Sample elements: ";
    std::cout << "First: " << largeVec[0] << ", Last: " << largeVec[largeVec.size() - 1] << std::endl;

    std::cout << "\n==== End of Examples ====" << std::endl;

    return 0;
}
