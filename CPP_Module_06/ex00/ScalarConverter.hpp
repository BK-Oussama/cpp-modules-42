
#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <limits>
#include <cmath>
#include <iomanip>
#include <cctype>
#include <cstdlib> 

enum e_types
{
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    PSEUDO_LITERAL,
    INVALID
};

class ScalarConverter
{

private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &copy);
    ScalarConverter &operator=(const ScalarConverter &other);
    ~ScalarConverter();

public:
    static void convert(const std::string &literal);
};




// static bool isIntValid(const std::string &literal);
// static bool isFloatValid(const std::string &literal);
// static bool isDoubleValid(const std::string &literal);

// static e_types getType(const std::string &literal);

// static void printChar(const std::string &literal);



#endif