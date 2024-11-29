# Assignment 006 Vector

This project implements a C++ class `Vector<T>` that supports many common operations of dynamic arrays.

## File Structure

```txt
.
├── CMakeLists.txt
├── README.md
├── script
│   ├── compile.sh
│   ├── package.sh
│   └── test.sh
├── src
│   ├── example.cpp
│   ├── Vector.h
│   └── Vector.tpp
└── test
    └── tests.cpp
```

- **`src/`**: Contains the implementation files for the `Vector<T>` class, including both header and source files.
- **`test/`**: Contains test code that uses Google Test to validate the functionality of the `Vector<T>` class.
- **`script/`**: Contains auxiliary scripts for packaging and running tests.

## Environment Requirements

- CMake 3.5.0 or higher
- A C++ compiler support C++17 standards
- Google Test library

### Compile and Test

Run `script/test.sh`. Then you will see:

```txt
...
[ 50%] Building CXX object CMakeFiles/tests.dir/test/tests.cpp.o
[100%] Linking CXX executable tests
[100%] Built target tests
[==========] Running 11 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 11 tests from VectorTest
[ RUN      ] VectorTest.DefaultConstructor
[       OK ] VectorTest.DefaultConstructor (0 ms)
[ RUN      ] VectorTest.ConstructorWithSize
[       OK ] VectorTest.ConstructorWithSize (0 ms)
[ RUN      ] VectorTest.CopyConstructor
[       OK ] VectorTest.CopyConstructor (0 ms)
[ RUN      ] VectorTest.PushBackSimple
[       OK ] VectorTest.PushBackSimple (0 ms)
[ RUN      ] VectorTest.ClearSimple
[       OK ] VectorTest.ClearSimple (0 ms)
[ RUN      ] VectorTest.AtOutOfBounds
[       OK ] VectorTest.AtOutOfBounds (0 ms)
[ RUN      ] VectorTest.DynamicResizing
[       OK ] VectorTest.DynamicResizing (0 ms)
[ RUN      ] VectorTest.LargeScaleData
[       OK ] VectorTest.LargeScaleData (11 ms)
[ RUN      ] VectorTest.MultipleVectorInteraction
[       OK ] VectorTest.MultipleVectorInteraction (0 ms)
[ RUN      ] VectorTest.MixedOperations
[       OK ] VectorTest.MixedOperations (0 ms)
[ RUN      ] VectorTest.ExceptionHandlingStability
[       OK ] VectorTest.ExceptionHandlingStability (0 ms)
[----------] 11 tests from VectorTest (12 ms total)

[----------] Global test environment tear-down
[==========] 11 tests from 1 test suite ran. (12 ms total)
[  PASSED  ] 11 tests.
```

### Example Usage

See `src/example.cpp` for use cases.
