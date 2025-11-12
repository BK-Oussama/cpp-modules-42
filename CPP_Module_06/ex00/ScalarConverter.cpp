
#include "ScalarConverter.hpp"

#include <string>
#include <cctype>
#include <iostream>

ScalarConverter::ScalarConverter() {};

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
    (void)copy;
};

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    (void)other;
    return *this;
};

ScalarConverter::~ScalarConverter() {};

static bool isFloatValid(const std::string &literal)
{
    // .0f | 0.f | -0.f -.0f
    if (literal.length() >= 3 && literal.find('.') != std::string::npos && literal.find('f') != std::string::npos)
    {
        // f character should appear only after the decimal dot, befor the decimal dot its not a valid float number
        // skip the sign if exists.
        size_t len = literal.length();
        if (literal[len - 1] != 'f')
            return false;

        size_t i = 0;
        if (literal[i] == '+' || literal[i] == '-')
            i++;

        bool decimal_found = false;
        bool digit_found = false;

        while (i < len - 1)
        {
            char c = literal[i];

            if (std::isdigit(c))
                digit_found = true;
            else if (c == '.')
            {
                if (decimal_found)
                    return false;
                decimal_found = true;
            }
            else
                return false;
            i++;
        }
        // at least one digit should exists!
        if (digit_found == false)
            return false;
        return true;
    }
    return false;
}

static bool isDoubleValid(const std::string &literal)
{

    if (literal == "." || literal == "+." || literal == "-.")
        return false;

    if (literal.length() >= 2 && literal.find('.') != std::string::npos)
    {

        size_t i = 0;
        if (literal[i] == '+' || literal[i] == '-')
            i++;

        bool decimal_found = false;
        while (i < literal.length())
        {
            char c = literal[i];
            if (std::isdigit(c) || c == '.')
            {
                if (c == '.')
                {
                    if (decimal_found)
                        return false;

                    decimal_found = true;
                }
            }
            else
                return false;
            i++;
        }
        return true;
    }
    else
        return false;
}

static bool isIntValid(const std::string &literal)
{
    size_t len = literal.length();
    if (len >= 1)
    {
        size_t i = 0;
        if (literal[i] == '+' || literal[i] == '-')
            i++;

        while (i < literal.length())
        {
            if (!std::isdigit(literal[i]))
                return false;
            i++;
        }
        return true;
    }
    else
        return false;
}

static e_types getType(const std::string &literal)
{

    // CHARS
    // 'c' [0]= ' | [1] = c | [2] = '
    if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'')
    {
        // we gonna check this later to print non displayable or printing the char
        // if (std::isprint(literal[2]))
        return CHAR;
    }

    // PSEUDO_LITERAL
    else if (literal == "nan" || literal == "nanf" || literal == "+inf" || literal == "-inf" ||
             literal == "+inff" || literal == "-inff" || literal == "inf" || literal == "inff")
    {
        return PSEUDO_LITERAL;
    }

    // FLOAT
    // VALID: 0.0f .0f  -----> NOT VALID: f.0
    // Check for float: must have '.' AND end with 'f' (and not be a pseudo-literal like "nanf")
    else if (isFloatValid(literal))
    {
        return FLOAT;
    }

    // DOUBLE
    // Check for double (has a '.')
    // handle such numbers: .0 | 0. --> only dot '.' is not valid
    else if (isDoubleValid(literal))
    {
        return DOUBLE;
    }

    // INT
    // Otherwise, check if it contains only digits and a sign.
    else if (isIntValid(literal))
        return INT;
    else
        return INVALID;
}

static void printChar(const std::string &literal)
{
    char char_val = literal[1];

    double base_val = static_cast<double>(char_val);

    std::cout << "char: ";
    if (!std::isprint(static_cast<int>(char_val)))
    {
        std::cout << "Non displayable" << std::endl;
    }
    else
    {
        std::cout << "'" << char_val << "'" << std::endl;
    }

    std::cout << "int: " << static_cast<int>(base_val) << std::endl;

    std::cout << "float: ";
    std::cout << std::fixed << std::setprecision(1) << static_cast<float>(base_val) << "f" << std::endl;

    std::cout << "double: ";
    std::cout << std::fixed << std::setprecision(1) << base_val << std::endl;
}

static void printPseudoLiteral(const std::string &literal)
{
    std::cout << "char: impossible" << std::endl;

    std::cout << "int: impossible" << std::endl;

    std::cout << "float: ";
    if (literal == "nan" || literal == "+inf" || literal == "-inf" || literal == "inf")
    {
        std::cout << literal << "f" << std::endl;
    }
    // If the input was already a float pseudo-literal (has 'f'), we print it as is.
    else if (literal == "nanf" || literal == "+inff" || literal == "-inff" || literal == "inff")
    {
        std::cout << literal << std::endl;
    }

    std::cout << "double: ";
    if (literal == "nanf" || literal == "+inff" || literal == "-inff" || literal == "inff")
    {
        std::cout << literal.substr(0, literal.length() - 1) << std::endl;
    }
    else if (literal == "nan" || literal == "+inf" || literal == "-inf" || literal == "inf")
    {
        std::cout << literal << std::endl;
    }
}

static void printInt(const std::string &literal)
{
    char *end = NULL;
    long double base_val = std::strtold(literal.c_str(), &end);

    std::cout << "char: ";
    if (base_val > 127.0L || base_val < 0.0L)
        std::cout << "impossible" << std::endl;
    else if (!std::isprint(static_cast<int>(base_val)))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(base_val) << "'" << std::endl;

    std::cout << "int: ";
    if (base_val > static_cast<long double>(std::numeric_limits<int>::max()) ||
        base_val < static_cast<long double>(std::numeric_limits<int>::min()))
    {
        std::cout << "impossible" << std::endl;
    }
    else
        std::cout << static_cast<int>(base_val) << std::endl;

    std::cout << "float: ";
    std::cout << std::fixed << std::setprecision(1);
    std::cout << static_cast<float>(base_val) << "f" << std::endl;

    std::cout << "double: ";
    std::cout << std::fixed << std::setprecision(1);
    std::cout << base_val << std::endl;
}

static void printFloat(const std::string &literal)
{
    char *end = NULL;
    long double base_val = std::strtold(literal.c_str(), &end);

    bool int_impossible = (base_val > static_cast<long double>(std::numeric_limits<int>::max()) ||
                           base_val < static_cast<long double>(std::numeric_limits<int>::min()));

    std::cout << "char: ";
    if (base_val > 127.0L || base_val < 0.0L)
        std::cout << "impossible" << std::endl;
    else if (!std::isprint(static_cast<int>(base_val)))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(base_val) << "'" << std::endl;

    std::cout << "int: ";
    if (int_impossible)
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(base_val) << std::endl;

    bool float_impossible = (base_val > static_cast<long double>(std::numeric_limits<float>::max()) ||
                             base_val < static_cast<long double>(-std::numeric_limits<float>::max()));

    std::cout << "float: ";
    if (float_impossible)
    {
        // If it overflows float, output INF/inff
        if (base_val > 0)
            std::cout << "+inff" << std::endl;
        else
            std::cout << "-inff" << std::endl;
    }
    else
    {
        std::cout << std::fixed << std::setprecision(1);
        std::cout << static_cast<float>(base_val) << "f" << std::endl;
    }

    bool double_impossible = (base_val > static_cast<long double>(std::numeric_limits<double>::max()) ||
                              base_val < static_cast<long double>(-std::numeric_limits<double>::max()));
    std::cout << "double: ";
    if (double_impossible)
    {
        // If it overflows double, output INF/inf
        if (base_val > 0)
            std::cout << "+inf" << std::endl;
        else
            std::cout << "-inf" << std::endl;
    }
    else
    {
        std::cout << std::fixed << std::setprecision(1);
        std::cout << base_val << std::endl;
    }
}

static void printDouble(const std::string &literal)
{
    char *end = NULL;
    long double base_val = std::strtold(literal.c_str(), &end);

    bool int_impossible = (base_val > static_cast<long double>(std::numeric_limits<int>::max()) ||
                           base_val < static_cast<long double>(std::numeric_limits<int>::min()));

    std::cout << "char: ";
    if (base_val > 127.0L || base_val < 0.0L)
        std::cout << "impossible" << std::endl;
    else if (!std::isprint(static_cast<int>(base_val)))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(base_val) << "'" << std::endl;

    std::cout << "int: ";
    if (int_impossible)
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(base_val) << std::endl;


    bool float_impossible = (base_val > static_cast<long double>(std::numeric_limits<float>::max()) ||
                             base_val < static_cast<long double>(-std::numeric_limits<float>::max()));
    std::cout << "float: ";
    if (float_impossible)
    {
        if (base_val > 0)
            std::cout << "+inff" << std::endl;
        else
            std::cout << "-inff" << std::endl;
    }
    else
    {
        std::cout << std::fixed << std::setprecision(1);
        std::cout << static_cast<float>(base_val) << "f" << std::endl;
    }


    bool double_impossible = (base_val > static_cast<long double>(std::numeric_limits<double>::max()) ||
                              base_val < static_cast<long double>(-std::numeric_limits<double>::max()));
    std::cout << "double: ";
    if (double_impossible)
    {
        if (base_val > 0)
            std::cout << "+inf" << std::endl;
        else
            std::cout << "-inf" << std::endl;
    }
    else
    {
        std::cout << std::fixed << std::setprecision(1);
        std::cout << base_val << std::endl;
    }
}

void ScalarConverter::convert(const std::string &literal)
{
    e_types type = getType(literal);

    switch (type)
    {
    case INVALID:
        std::cout << "Invalid input" << std::endl;
        break;
    case CHAR:
        printChar(literal);
        break;
    case PSEUDO_LITERAL:
        printPseudoLiteral(literal);
        break;
    case INT:
        printInt(literal);
        break;
    case FLOAT:
        printFloat(literal);
        break;
    case DOUBLE:
        printDouble(literal);
        break;
    }
}
