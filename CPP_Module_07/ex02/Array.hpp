

#ifndef ARRAY_HPP
# define ARRAY_HPP


template <typename T>
class Array
{
    private:
        T               *m_array;
        unsigned int    m_size;

    public:
        Array();
        Array(unsigned int n);
        Array(const Array &copy);
        Array &operator=(const Array &other);
        ~Array();


        T &operator[] (unsigned int index);
        const  T &operator[] (unsigned int index) const;
        unsigned int size() const;
        
};




#include "Array.tpp"

#endif