# Assignment 005 Fraction

This project implements a C++ class `Fraction` that represents a fraction and provides arithmetic and comparison operations. The class supports addition, subtraction, multiplication, division, and comparison operations for fractions. It also includes functionality to simplify fractions, convert them to strings, and handle conversion from decimal strings. The project includes unit tests using the Google Test framework.

## File Structure

```txt
├── CMakeLists.txt
├── README.md
├── script
│   ├── package.sh
│   └── test.sh
├── src
│   ├── Fraction.cpp
│   └── Fraction.h
└── test
    └── tests.cpp
```

- **`src/`**: Contains the implementation files for the `Fraction` class, including both header and source files.
- **`test/`**: Contains test code that uses Google Test to validate the functionality of the `Fraction` class.
- **`script/`**: Contains auxiliary scripts for packaging and running tests.

## Environment Requirements

- CMake 3.5.0 or higher
- A C++ compiler support C++17 standards
- Google Test library

### Compile and Test

Run `scripts/test.sh`. Then you will see:

```txt
...
[ 33%] Building CXX object CMakeFiles/tests.dir/test/tests.cpp.o
[ 66%] Building CXX object CMakeFiles/tests.dir/src/Fraction.cpp.o
[100%] Linking CXX executable tests
[100%] Built target tests
[==========] Running 10 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 10 tests from FractionTest
[ RUN      ] FractionTest.ConstructorValidInput
[       OK ] FractionTest.ConstructorValidInput (0 ms)
[ RUN      ] FractionTest.ConstructorFromDecimal
[       OK ] FractionTest.ConstructorFromDecimal (0 ms)
[ RUN      ] FractionTest.Simplification
[       OK ] FractionTest.Simplification (0 ms)
[ RUN      ] FractionTest.ArithmeticOperations
[       OK ] FractionTest.ArithmeticOperations (0 ms)
[ RUN      ] FractionTest.ComparisonOperators
[       OK ] FractionTest.ComparisonOperators (0 ms)
[ RUN      ] FractionTest.ConversionToDouble
[       OK ] FractionTest.ConversionToDouble (0 ms)
[ RUN      ] FractionTest.InputOutputOperators
[       OK ] FractionTest.InputOutputOperators (0 ms)
[ RUN      ] FractionTest.NegativeFractions
[       OK ] FractionTest.NegativeFractions (0 ms)
[ RUN      ] FractionTest.LargeNumbers
[       OK ] FractionTest.LargeNumbers (0 ms)
[ RUN      ] FractionTest.EdgeCaseDecimalInput
[       OK ] FractionTest.EdgeCaseDecimalInput (0 ms)
[----------] 10 tests from FractionTest (0 ms total)

[----------] Global test environment tear-down
[==========] 10 tests from 1 test suite ran. (0 ms total)
[  PASSED  ] 10 tests.
```

### Example Usage

```cpp
#include "Fraction.h"
#include <iostream>

int main() {
    Fraction frac1(2, 3); // Creates fraction 2/3
    Fraction frac2(3, 4); // Creates fraction 3/4
    
    Fraction result = frac1 + frac2; // Adds the two fractions
    std::cout << "Result of addition: " << result.to_string() << std::endl; // Output: "17/12"
    
    result.simplify(); // Simplifies the fraction
    std::cout << "Simplified result: " << result.to_string() << std::endl; // Output: "17/12"
    
    double decimalValue = static_cast<double>(frac1); // Converts to double
    std::cout << "Fraction as double: " << decimalValue << std::endl; // Output: 0.666667
    
    return 0;
}
```
