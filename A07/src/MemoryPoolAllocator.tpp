#ifndef MEMORYPOOLALLOCATOR_TPP
#define MEMORYPOOLALLOCATOR_TPP

#include <memory>
#include <iostream>
#include <cstdlib>
#include <limits>

/**
 * @class MemoryPoolAllocator
 * @brief A custom memory allocator that uses a memory pool for efficient allocation and deallocation.
 *
 * This allocator manages memory in blocks and reuses free blocks to minimize overhead.
 * It provides basic functionalities required by STL allocators, such as allocate, deallocate,
 * construct, and destroy.
 *
 * @tparam T The type of object to allocate.
 */
template<class T>
class MemoryPoolAllocator {
public:
    /**
     * @brief Minimum block size for allocation.
     */
#define MIN_BLOCK_SIZE 1024

    using value_type = T;
    using size_type = size_t;
    using difference_type = ptrdiff_t;
    using pointer = value_type*;
    using const_pointer = const value_type*;
    using reference = value_type&;
    using const_reference = const value_type&;

    /**
     * @brief Default constructor. Initializes an empty free block list.
     */
    MemoryPoolAllocator() {
        free_blocks = nullptr;
    }


    /**
     * @brief Destructor. Frees all remaining blocks in the free list.
     */
    ~MemoryPoolAllocator() {
        while (free_blocks != nullptr) {
            Block* temp = free_blocks;
            free_blocks = free_blocks->next;
            delete temp;
        }
    }

    /**
     * @brief Returns the address of a reference.
     *
     * @param _Val The reference to the object.
     * @return The pointer to the object.
     */
    pointer address(reference _Val) const noexcept {
        return &(_Val);
    }

    /**
     * @brief Returns the address of a constant reference.
     *
     * @param _Val The constant reference to the object.
     * @return The pointer to the object.
     */
    const_pointer address(const_reference _Val) const noexcept {
        return &(_Val);
    }

    /**
     * @brief Deallocates a block of memory and returns it to the free list.
     *
     * @param address The pointer to the memory block.
     * @param count The number of elements in the block.
     */
    void deallocate(pointer address, size_type count) {
        Block* block = new Block();
        block->data = address;
        block->size = count;
        block->next = free_blocks;
        free_blocks = block;
    }

    /**
     * @brief Allocates a block of memory. Reuses a free block if available.
     *
     * @param count The number of elements to allocate.
     * @return A pointer to the allocated memory block.
     */
    pointer allocate(size_type count) {
        if (count < MIN_BLOCK_SIZE) {
            count = MIN_BLOCK_SIZE;
        }

        // Find the first free block that is big enough
        Block** current = &free_blocks;
        while (*current != nullptr) {
            Block* block = *current;
            if (block->size >= count) {
                // Split the block if it is too large
                if (block->size > count) {
                    *current = block->split(count);
                }
                // Remove the block from the free list
                *current = block->next;
                return block->data;
            }
            current = &block->next;
        }

        // If no suitable block is found, allocate a new one
        Block* new_block = new Block(count);
        return new_block->data;
    }

    /**
     * @brief Destroys an object at a given pointer by invoking its destructor.
     *
     * @tparam U The type of the object.
     * @param ptr The pointer to the object to destroy.
     */
    template<class U>
    void destroy(U* ptr) {
        if (ptr != nullptr) {
            ptr->~U();
        }
    }

    /**
     * @brief Constructs an object at a given pointer with the provided arguments.
     *
     * @tparam Obj The type of the object to construct.
     * @tparam Args The types of arguments for the constructor.
     * @param ptr The pointer to the memory location.
     * @param args The arguments to pass to the constructor.
     */
    template<class Obj, class... Args>
    void construct(Obj* ptr, Args&&... args) {
        new (ptr) Obj(std::forward<Args>(args)...);
    }

    /**
     * @brief Compares two allocators for equality. Always returns false for different instances.
     *
     * @param other Another allocator to compare.
     * @return True if the allocators are the same instance, false otherwise.
     */
    bool operator==(const MemoryPoolAllocator& other) const {
        return this == &other;
    }

    /**
     * @brief Compares two allocators for inequality.
     *
     * @param other Another allocator to compare.
     * @return True if the allocators are different instances, false otherwise.
     */
    bool operator!=(const MemoryPoolAllocator& other) const {
        return this != &other;
    }

private:
    /**
     * @struct Block
     * @brief Represents a memory block in the allocator.
     */
    struct Block {
        size_t size;        ///< Size of the block (number of elements).
        value_type* data;   ///< Pointer to the block's data.
        Block* next;        ///< Pointer to the next block in the list.

        /**
         * @brief Default constructor. Creates an empty block.
         */
        Block() {
            this->size = 0;
            this->data = nullptr;
            this->next = nullptr;
        }

        /**
         * @brief Constructor. Allocates a block of the specified size.
         *
         * @param size The number of elements to allocate.
         */
        Block(size_type size) {
            this->size = size;
            this->data = static_cast<value_type*>(std::malloc(size * sizeof(value_type)));
            this->next = nullptr;
        }

        /**
         * @brief Destructor. Frees the allocated memory.
         */
        ~Block() {
            std::free(data);
        }

        /**
         * @brief Splits the block into two blocks if it is larger than the requested size.
         *
         * @param size The size of the first block after splitting.
         * @return A pointer to the remaining part of the block.
         */
        Block* split(size_type size) {
            Block* new_block = new Block();
            new_block->size = this->size - size;
            new_block->data = &this->data[size];
            new_block->next = this->next;
            this->size = size;
            this->next = new_block;
            return this;
        }
    };

    Block* free_blocks; ///< Pointer to the head of the free block list.
};

#endif // MEMORYPOOLALLOCATOR_CPP
