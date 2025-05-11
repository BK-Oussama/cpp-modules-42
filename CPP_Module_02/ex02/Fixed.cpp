#include "Fixed.hpp"

// Default constructor
Fixed::Fixed() : _rawBits(0) {
    // Default init
}

// Int constructor
Fixed::Fixed(const int n) {
    _rawBits = n << _fractionalBits;
}

// Float constructor
Fixed::Fixed(const float f) {
    _rawBits = roundf(f * (1 << _fractionalBits));
}

// Copy constructor
Fixed::Fixed(const Fixed& other) {
    *this = other;
}

// Copy assignment
Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other) {
        _rawBits = other._rawBits;
    }
    return *this;
}

// Destructor
Fixed::~Fixed() {
    // Cleanup if needed
}

// Getters and setters
int Fixed::getRawBits(void) const {
    return _rawBits;
}

void Fixed::setRawBits(int const raw) {
    _rawBits = raw;
}

// Conversion functions
float Fixed::toFloat(void) const {
    return static_cast<float>(_rawBits) / (1 << _fractionalBits);
}

int Fixed::toInt(void) const {
    return _rawBits >> _fractionalBits;
}

// Stream overload
std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
    out << fixed.toFloat();
    return out;
}

// Arithmetic operators
Fixed Fixed::operator+(const Fixed& other) const {
    float result = this->toFloat() + other.toFloat();
    return Fixed(result);
}

Fixed Fixed::operator-(const Fixed& other) const {
    float result = this->toFloat() - other.toFloat();
    return Fixed(result);
}

Fixed Fixed::operator*(const Fixed& other) const {
    float result = this->toFloat() * other.toFloat();
    return Fixed(result);
}

Fixed Fixed::operator/(const Fixed& other) const {
    float divisor = other.toFloat();
    if (divisor != 0.0f) {
        float result = this->toFloat() / divisor;
        return Fixed(result);
    } else {
        std::cerr << "Warning: Division by zero. Returning Fixed(0)." << std::endl;
        return Fixed(0);
    }
}

// Comparison operators
bool Fixed::operator>(const Fixed& other) const {
    if (this->_rawBits > other._rawBits) {
        return true;
    } else {
        return false;
    }
}

bool Fixed::operator<(const Fixed& other) const {
    if (this->_rawBits < other._rawBits) {
        return true;
    } else {
        return false;
    }
}

bool Fixed::operator>=(const Fixed& other) const {
    if (this->_rawBits >= other._rawBits) {
        return true;
    } else {
        return false;
    }
}

bool Fixed::operator<=(const Fixed& other) const {
    if (this->_rawBits <= other._rawBits) {
        return true;
    } else {
        return false;
    }
}

bool Fixed::operator==(const Fixed& other) const {
    if (this->_rawBits == other._rawBits) {
        return true;
    } else {
        return false;
    }
}

bool Fixed::operator!=(const Fixed& other) const {
    if (this->_rawBits != other._rawBits) {
        return true;
    } else {
        return false;
    }
}

// Increment / Decrement
Fixed& Fixed::operator++() {
    _rawBits++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    _rawBits++;
    return temp;
}

Fixed& Fixed::operator--() {
    _rawBits--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    _rawBits--;
    return temp;
}

// Min/Max functions
Fixed& Fixed::min(Fixed& a, Fixed& b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}
