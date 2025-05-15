#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <iostream>
#include <stdexcept>

/**
 * @brief Generic dynamic array class template
 * 
 * @tparam T Type of elements stored
 */
template<typename T>
class Array {
private:
    T* data;              
    size_t size;          
    size_t capacity;      

    /**
     * @brief Deep copy helper
     * 
     * @param other Array to copy from
     */
    void deepCopy(const Array& other) 
    {
        data = new T[capacity];
        for (size_t i = 0; i < size; ++i)
            data[i] = other.data[i];
    }

    /**
     * @brief double allocated capacity of array 
     * 
     */
    void doubleCapacity() 
    {
        if (size < capacity) throw std::length_error("Too few elements to double capacity");
        T* temp = new T[capacity * 2];

        for(size_t i = 0; i < size; i++)
            temp[i] = data[i];

        delete[] data;
        data = temp;
    }
    
    /**
     * @brief halve allocated capacity of array 
     * 
     */
    void halveCapacity() 
    {
        if (size > capacity / 2) throw std::length_error("Too many elements to halve capacity");
        if (capacity <= 2) return;

        T* temp = new T[capacity / 2];

        for(size_t i = 0; i < size; i++)
            temp[i] = data[i];

        delete[] data;
        data = temp;
    }


public:
    /**
     * @brief Constructor
     * 
     * @param cap Initial capacity
     */
    Array(size_t cap = 16)
        : data(nullptr), size(0), capacity(cap) 
    {
        data = new T[capacity];
    }

    /**
     * @brief Copy constructor
     * 
     * @param other Array to copy
     */
    Array(const Array& other)
        : data(nullptr), size(other.size), capacity(other.capacity) 
    {
        deepCopy(other);
    }

    /**
     * @brief Copy assignment
     * 
     * @param other Array to copy
     * @return Array& Reference to this
     */
    Array& operator=(const Array& other) 
    {
        if (this == &other) return *this;
        delete[] data;
        size = other.size;
        capacity = other.capacity;
        deepCopy(other);
        return *this;
    }

    /**
     * @brief Destructor
     */
    ~Array() 
    {
        delete[] data;
    }

    /**
     * @brief Element access (non-const)
     * 
     * @param idx Index
     * @return T& Reference to element
     */
    T& operator[](size_t idx) 
    {
        if (idx >= size) throw std::out_of_range("Index out of range");
        return data[idx];
    }

    /**
     * @brief Element access (const)
     * 
     * @param idx Index
     * @return const T& Const reference to element
     */
    const T& operator[](size_t idx) const 
    {
        if (idx >= size) throw std::out_of_range("Index out of range");
        return data[idx];
    }

    /**
     * @brief print array elements in order with separator string 
     * 
     * @param os std::ostream to print to
     * @param separator string that separates elements
     */
    void print(std::ostream& os, const char* separator) const
    {
        for (size_t i = 0; i < size; ++i) {
            os << data[i];
            if (i < size - 1) os << separator;
        }
    }


    /**
     * @brief Insert an element at a specific index
     * 
     * @param elem Element to insert
     * @param idx Index at which to insert
     */
    void insert(const T& elem, size_t idx) 
    {
        if (idx > size) throw std::out_of_range("Insert index out of bounds");
        if (size >= capacity) doubleCapacity(); 

        for (size_t i = size; i > idx; i--) {
            data[i] = data[i - 1];
        }

        data[idx] = elem;
        size++;
    }

    /**
     * @brief Insert an element at the end of the array
     * 
     * @param elem Element to insert
     */
    void insert(const T& elem) 
    {
        insert(elem, size);
    }

    /**
     * @brief Remove element at a specific index
     * 
     * @param idx Index to remove
     */
    void remove(size_t idx) 
    {
        if (idx >= size) throw std::out_of_range("Remove index out of bounds");
        if (size < capacity/2) halveCapacity();

        for (size_t i = idx; i < size - 1; ++i) {
            data[i] = data[i + 1];
        }

        size--;
    }

    /**
     * @brief Remove the last element
     */
    void remove() 
    {
        remove(size - 1);
    }

    /**
     * @brief Get the current size
     * 
     * @return size_t Number of elements
     */
    size_t getSize() const 
    {
        return size;
    }

    /**
     * @brief Get the current capacity
     * 
     * @return size_t Allocated capacity
     */
    size_t getCapacity() const 
    {
        return capacity;
    }

};

/**
 * @brief Output stream operator for Array
 * 
 * @tparam T Type of elements
 * @param os Output stream
 * @param arr Array to output
 * @return std::ostream& Reference to output stream
 */
template<typename T>
std::ostream& operator<<(std::ostream& os, const Array<T>& arr)
{
    arr.print(os, ", ");
    return os;
}

#endif // ARRAY_HPP
