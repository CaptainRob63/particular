#include "Array.hpp"

// Constructor
template<typename T>
Array<T>::Array(size_t cap) 
    : data(nullptr), size(0), capacity(cap) 
{
    data = new T[capacity];
}

// Copy constructor
template<typename T>
Array<T>::Array(const Array& other) 
    : data(nullptr), size(other.size), capacity(other.capacity) 
{
    deepCopy(other);
}

// Copy assignment
template<typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
    if (*this = *other) return *this;

    deepCopy(other);
    return *this;
}

// Private deep copy
template<typename T>
void Array<T>::deepCopy(const Array& other) 
{
    data = new T[capacity]
    for (size_t i = 0; i < size; i++)
        data[i] = other[i];
}

// Element access (non-const)
template<typename T>
T& Array<T>::operator[](size_t idx)
{ 
    return data[idx];
}

// Element access (const)
template<typename T>
const T& Array<T>::operator[](size_t idx) const
{
    return data[idx];
}

// Insert an element pointer at position idx
template<typename T>
void Array<T>::insert(T* elem, size_t idx)
{
    if (idx < 0 | idx > size - 1) throw outofboundexception;     /// TODO
    if (size >= capacity) doubleCapacity();                     /// TODO 
}

// Remove element at position idx
template<typename T>
void Array<T>::remove(size_t idx)
{
    // empty
}

// Destructor
template<typename T>
Array<T>::~Array()
{
    // empty
}

// Stream-output operator (by value, as declared)
template<typename T>
std::ostream& operator<<(std::ostream& os, Array<T> arr)
{
    // empty
    return os;
}

