#let refbox(content, ..box_args, color: gray, width: 100%) = [
  #block(
    content,
    stroke: (left: 5pt + color.lighten((50%))),
    fill: color.lighten(80%),
    inset: (left: 1em, top: 0.5em, bottom: 0.5em, right: 0.5em),
    width: width)
]

#let mono_font = ("JetBrainsMono NF", "Source Han Sans SC")

#set text(font: "Source Han Serif SC", size: 12pt, top-edge: 1em)
#show raw: set text(font: mono_font)

#show heading.where(level: 1): it => {align(center, it)}
#set heading(numbering: (..nums) => {
  let arr = nums.pos().slice(1)
  if (arr.len() == 0) { return }
  if (arr.len() == 1) { return numbering("1.", ..arr) }
  else { return numbering("1.", ..arr.slice(1)) }

})

#let ubox(content, stroke: 0.5pt, outset: 2pt, ..box-args) = {
  box(
    align(center, content),
    stroke: (bottom: stroke),
    outset: (bottom: outset),
    ..box-args
    )
}

#align(center)[
  #set text(size: 16pt, font: ("New Computer Modern", "Source Han Serif SC"))

  #text(size: 1.5em)[*Object-oriented Programming*]
  #v(0.2em)
  #text(size: 1.8em)[*Assignment 007:\ STL allocator + memory pool*]
  #v(3em)
  #image("./ZJU-LOGO.png", width: 50%)
  #v(3em)
  Author: 刘仁钦\
  Date: #datetime.today().display("[year]/[month]/[day]")
]

#pagebreak(weak: true)

#outline(title: "Table of Contents", indent: true)

#set page(numbering: "1 / 1")
#counter(page).update(1)

== Overview

This project implements a custom allocator to replace the default allocator `std::Allocator<T>`. And the allocator uses memory pool to speed up the dynamic allocation of a large number of small blocks and to reduce memory fragmentation. This allocator can used with some STL containers like `std::vector` and `std::map`.

== File Structure

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

- *`src/`*: Contains the implementation file.
- *`test/`*: Contains test code.
- *`script/`*: Contains auxiliary scripts for packaging and running tests.


== Environment Requirements

- CMake 3.5.0 or higher
- A C++ compiler support C++11 standards

== Compile and Test

Run `script/compile.sh` for compilation.
Run `script/test.sh` for test.

== Class Design

The class `MemoryPoolAllocator` is designed to replace the default allocator `std::Allocator<T>`. It uses a memory pool to speed up the dynamic allocation of a large number of small blocks and reduce memory fragmentation. The class provides the following member functions:

=== Constructor and Destructor
- *`MemoryPoolAllocator()`*  
  Initializes an empty free block list for the allocator.

- *`~MemoryPoolAllocator()`*  
  Frees all remaining memory blocks in the free block list, ensuring no memory leaks.

=== Address Functions
- *`pointer address(reference _Val) const noexcept`*  
  Returns the address of a given reference `_Val`.

- *`const_pointer address(const_reference _Val) const noexcept`*  
  Returns the address of a constant reference `_Val`.

=== Memory Management
- *`void deallocate(pointer address, size_type count)`*  
  Deallocates a block of memory and adds it to the free block list for reuse.

- *`pointer allocate(size_type count)`*  
  Allocates a block of memory large enough to hold `count` elements. It reuses a free block if available; otherwise, it creates a new block.

=== Object Construction and Destruction
- *`template<class U> void destroy(U* ptr)`*  
  Destroys an object at the given pointer `ptr` by calling its destructor.

- *`template<class Obj, class... Args> void construct(Obj* ptr, Args&&... args)`*  
  Constructs an object of type `Obj` at the given pointer `ptr` using the provided arguments `args`.

=== Comparison Operators
- *`bool operator==(const MemoryPoolAllocator& other) const`*  
  Compares two allocators for equality. Returns `true` only if they are the same instance.

- *`bool operator!=(const MemoryPoolAllocator& other) const`*  
  Compares two allocators for inequality. Returns `true` if they are different instances.

=== Private Block Structure

The allocator manages memory using a linked list of `Block` objects, defined as follows:

- *Members*:
  - `size_t size`: The size of the block (number of elements).
  - `value_type* data`: Pointer to the block's data.
  - `Block* next`: Pointer to the next block in the list.
  
- *Constructors*:
  - `Block()`: Creates an empty block with `size = 0` and `data = nullptr`.
  - `Block(size_type size)`: Allocates a block of memory large enough to hold `size` elements.

- *Destructor*:
  Frees the allocated memory for the block.

- *`Block* split(size_type size)`*:  
  Splits a large block into two smaller blocks, keeping the first part of the requested size and returning a pointer to the remaining block.

The private field `Block* free_blocks` is the head of a list of blocks that are available for reuse. As is shown in the figure below:

#figure(
  image("free-list.png"),
  caption: "Free list structure"
)

== Code Implementation

Here is the code inplementation of this assignment, in the class `MemoryPoolAllocator` in the file `src/MemoryPoolAllocator.tpp`

#raw(read("../src/MemoryPoolAllocator.tpp"), lang: "cpp")

== Test Cases and Results

I use the provided test using `std::vector`, and designed my extra test using `std::map` as a bonus.

Output of test program `build/tests`:

```
Testing vector creation
Testing vector resize
Testing vector assignment
correct assignment in vecints: 3164
correct assignment in vecpts: 5605
Testing vector destruction
Testing map creation and insertion
Testing map assignment
correct assignment in mapints: 608
correct assignment in mappts: 3902
Testing map destruction
Testing complete
```

And the screenshot of the test program output is below:

#figure(
  image("screenshot.png"),
  caption: "Test program output"
)

#table(columns: 4,
  [*Index*],[*STL Container*],[*Operation*], [*Status*],
  [1], [`std::vector`], [creation], [passed],
  [2], [`std::vector`], [resize], [passed],
  [3], [`std::vector`], [assignment], [passed],
  [4], [`std::vector`], [destruction], [passed],
  [5], [`std::map`], [creation and insertion], [passed],
  [6], [`std::map`], [assignment], [passed],
  [7], [`std::map`], [destruction], [passed],
)

== Test Code

The test code is in the file `test/tests.cpp`, and is as follows:

#raw(read("../test/tests.cpp"), lang: "cpp")