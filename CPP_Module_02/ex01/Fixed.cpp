#include "Fixed.hpp"

// Default constructor
Fixed::Fixed() : _rawBits(0) {
    std::cout << "Default constructor called" << std::endl;
}

// Int constructor
Fixed::Fixed(const int n) {
    std::cout << "Int constructor called" << std::endl;
    _rawBits = n << _fractionalBits;
}

// Float constructor // what round do exactly ? 
Fixed::Fixed(const float f) {
    std::cout << "Float constructor called" << std::endl;
    _rawBits = roundf(f * (1 << _fractionalBits));
}

// Copy constructor
Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

// Copy assignment
Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        _rawBits = other.getRawBits();
    }
    return *this;
}

// Destructor
Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

// Getter
int Fixed::getRawBits(void) const {
    return _rawBits;
}

// Setter
void Fixed::setRawBits(int const raw) {
    _rawBits = raw;
}

// Convert to float
float Fixed::toFloat(void) const {
    return (float)_rawBits / (1 << _fractionalBits);
}

// Convert to int
int Fixed::toInt(void) const {
    return _rawBits >> _fractionalBits;
}

// << operator overload
std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
    out << fixed.toFloat();
    return out;
}
