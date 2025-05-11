#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
private:
    int _rawBits;
    static const int _fractionalBits = 8;

public:
    Fixed();                            // Default constructor
    Fixed(const int n);                 // Int constructor
    Fixed(const float f);              // Float constructor
    Fixed(const Fixed& other);          // Copy constructor
    Fixed& operator=(const Fixed& other); // Copy assignment
    ~Fixed();                           // Destructor

    int getRawBits(void) const;
    void setRawBits(int const raw);

    float toFloat(void) const;
    int toInt(void) const;
};

// << overload
std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif
