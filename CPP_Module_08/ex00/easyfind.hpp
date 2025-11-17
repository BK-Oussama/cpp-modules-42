#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iostream>
#include <stdexcept>

class ElementNotFound: public std::exception
{
    virtual const char *what() const throw()
    {
        return ("Error: Element not found in container");
    }
};

template <typename T>
typename T::iterator easyfind(T &container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);

    if (container.end() == it)
        throw ElementNotFound();

    return it;
};

#endif

