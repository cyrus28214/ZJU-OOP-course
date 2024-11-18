#ifndef VECTOR_TPP
#define VECTOR_TPP

#include "Vector.h"

/**
 * @file Vector.tpp
 * @brief Implementation of the template class Vector.
 *
 * This file contains the implementation of the Vector class template,
 * a dynamic array similar to std::vector.
 */

 /**
  * @brief Default constructor. Creates an empty vector.
  */
template <class T>
Vector<T>::Vector()
    : m_pElements(nullptr), m_nSize(0), m_nCapacity(0)
{
    // No elements initially, size and capacity are both zero.
}

/**
 * @brief Constructor with specified size.
 *
 * Allocates storage for a given number of elements. The elements are default-initialized.
 *
 * @param size The number of elements to allocate space for.
 */
template <class T>
Vector<T>::Vector(int size)
    : m_nSize(size), m_nCapacity(size)
{
    m_pElements = new T[m_nCapacity]; // Allocate storage for 'size' elements.
}

/**
 * @brief Copy constructor. Performs a deep copy of the given vector.
 *
 * Allocates new storage and copies all elements from the source vector.
 *
 * @param r The source vector to copy.
 */
template <class T>
Vector<T>::Vector(const Vector& r)
    : m_nSize(r.m_nSize), m_nCapacity(r.m_nCapacity)
{
    m_pElements = new T[m_nCapacity]; // Allocate storage.
    std::copy(r.m_pElements, r.m_pElements + r.m_nSize, m_pElements); // Copy elements.
}

/**
 * @brief Destructor. Releases the allocated storage.
 */
template <class T>
Vector<T>::~Vector() {
    delete[] m_pElements; // Release allocated memory.
}

/**
 * @brief Accesses an element by index without bounds checking.
 *
 * @param index The index of the element to access.
 * @return Reference to the element at the specified index.
 * @note The behavior is undefined if the index is out of bounds.
 */
template <class T>
T& Vector<T>::operator[](int index) {
    return m_pElements[index]; // Direct access without checking.
}

/**
 * @brief Accesses an element by index with bounds checking.
 *
 * @param index The index of the element to access.
 * @return Reference to the element at the specified index.
 * @throws std::out_of_range If the index is out of bounds.
 */
template <class T>
T& Vector<T>::at(int index) {
    if (index < 0 || index >= m_nSize) {
        throw std::out_of_range("Index out of range"); // Throw exception for invalid index.
    }
    return m_pElements[index];
}

/**
 * @brief Gets the number of elements currently stored in the vector.
 *
 * @return The size of the vector.
 */
template <class T>
int Vector<T>::size() const {
    return m_nSize; // Return the current number of elements.
}

/**
 * @brief Adds an element to the end of the vector.
 *
 * If the current storage is full, the vector's capacity is doubled before adding the new element.
 *
 * @param x The element to add.
 */
template <class T>
void Vector<T>::push_back(const T& x) {
    if (m_nSize == m_nCapacity) {
        inflate(); // Expand capacity if necessary.
    }
    m_pElements[m_nSize++] = x; // Add element and increment size.
}

/**
 * @brief Removes all elements from the vector.
 *
 * Clears the contents of the vector and releases its memory.
 */
template <class T>
void Vector<T>::clear() {
    delete[] m_pElements; // Release allocated memory.
    m_pElements = nullptr; // Reset pointer to null.
    m_nSize = 0;           // Reset size.
    m_nCapacity = 0;       // Reset capacity.
}

/**
 * @brief Checks whether the vector is empty.
 *
 * @return True if the vector has no elements, otherwise false.
 */
template <class T>
bool Vector<T>::empty() const {
    return m_nSize == 0; // Return true if no elements are present.
}

/**
 * @brief Expands the storage capacity of the vector.
 *
 * Doubles the current capacity and reallocates storage, copying existing elements to the new storage.
 */
template <class T>
void Vector<T>::inflate() {
    // Calculate the new capacity: double the current capacity, or set to 1 if currently zero.
    m_nCapacity = m_nCapacity == 0 ? 1 : 2 * m_nCapacity;
    T* newElements = new T[m_nCapacity]; // Allocate new storage.

    if (m_pElements) {
        std::copy(m_pElements, m_pElements + m_nSize, newElements); // Copy existing elements.
        delete[] m_pElements; // Free old storage.
    }

    m_pElements = newElements; // Update storage pointer.
}

#endif // VECTOR_TPP
