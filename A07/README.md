# Assignment 007 STL allocator + memory pool

This project implements a custom allocator to replace the default allocator `std::Allocator<T>`. And the allocator uses memory pool to speed up the dynamic allocation of a large number of small blocks and to reduce memory fragmentation. This allocator can used with some STL containers like `std::vector` and `std::map`.

## Report

The PDF format report is at `report/report.pdf`. 

**The content in `report.pdf` is different from this `README.md` file.** So please check it out. 

## File Structure

```txt
.
├── build
├── CMakeLists.txt
├── README.md
├── script
│   ├── compile.sh
│   ├── package.sh
│   └── test.sh
├── src
│   └── MemoryPoolAllocator.tpp
└── test
    └── tests.cpp
```

- **`src/`**: Contains the implementation file.
- **`test/`**: Contains test code.
- **`script/`**: Contains auxiliary scripts for packaging and running tests.

## Environment Requirements

- CMake 3.5.0 or higher
- A C++ compiler support C++11 standards

### Compile and Test

Run `script/test.sh`. Then you will see:

```
Testing vector creation
Testing vector resize
Testing vector assignment
correct assignment in vecints: 337
correct assignment in vecpts: 3538
Testing vector destruction
Testing map creation and insertion
Testing map assignment
correct assignment in mapints: 841
correct assignment in mappts: 4531
Testing map destruction
Testing complete
```

### Example Usage

See `test/tests.cpp` for use cases.
