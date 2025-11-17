#include <iostream>
#include <string>
#include "iter.hpp"


template <typename T>
void increment(T &val)
{
    val++;
}

template <typename T>
void print_element(const T &val)
{
    std::cout << val << ", ";
}

void capitalize_first(std::string &str)
{
    if (!str.empty())
        str[0] = std::toupper(str[0]);
}

int main()
{
    std::cout << "\n-------------- Integer Array --------------" << std::endl;
    int intArray[] = {1, 2, 3, 4, 5};

    std::cout << "Before iter (increment): ";
    ::iter(intArray, 5, print_element<int>);
    std::cout << std::endl;

    ::iter(intArray, 5, increment<int>);

    std::cout << "After iter (increment): ";
    ::iter(intArray, 5, print_element<int>);
    std::cout << std::endl;


    std::cout << "\n-------------- String Array --------------" << std::endl;

    std::string strArray[] = {"hello", "world", "templates"};

    std::cout << "Before iter (capitalize): ";
    ::iter(strArray, 3, print_element<std::string>);
    std::cout << std::endl;

    ::iter(strArray, 3, capitalize_first);

    std::cout << "After iter (capitalize): ";
    ::iter(strArray, 3, print_element<std::string>);
    std::cout << std::endl;



    std::cout << "\n-------------- Float Array --------------" << std::endl;
    const float floatArray[] = {1.5f, 2.7f, 3.9f}; // const Array

    std::cout << "Contents: ";
    ::iter(floatArray, 3, print_element<float>);

    std::cout << std::endl;

    return 0;
}