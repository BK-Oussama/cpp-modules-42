#ifndef ARRAY_TPP
#define ARRAY_TPP

// #include "Array.hpp"

template <typename T>
Array<T>::Array() : m_array(NULL), m_size(0){};

template <typename T>
Array<T>::Array(unsigned int n) : m_array(NULL), m_size(n)
{
    m_array = new T[n]();
};

template <typename T>
Array<T>::Array(const Array<T> &copy) : m_array(NULL), m_size(copy.m_size)
{
    m_array = new T[m_size];

    unsigned int i = 0;
    while (i < m_size)
    {
        // deep copy
        m_array[i] = copy.m_array[i];
        i++;
    }
}

template <typename T>
Array<T>::~Array()
{
    if (m_array)
    {
        delete[] m_array;
        m_array = NULL;
    }
    std::cout << "Array destructor called\n";
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &other)
{
    if (this != &other)
    {
        // clean old constructed memory
        if (m_array)
        {
            delete[] m_array;
            m_array = NULL;
        }

        m_size = other.m_size;
        m_array = new T[m_size];

        unsigned int i = 0;
        while (i < m_size)
        {
            // deep copy
            m_array[i] = other.m_array[i];
        }
    }
    return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int i)
{
    if (i >= m_size)
        throw std::out_of_range("Array: Index out of bounds on non-const access");

    return m_array[i];
}

template <typename T>
const T &Array<T>::operator[](unsigned int i) const
{
    if (i >= m_size)
        throw std::out_of_range("Array: Index out of bounds on non-const access");

    return m_array[i];
}

template <typename T>
unsigned int Array<T>::size() const
{
    return m_size;
}

#endif