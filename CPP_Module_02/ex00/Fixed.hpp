#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
private:
    int _rawBits;                            // Raw fixed-point number value
    static const int _fractionalBits = 8;    // Always 8 bits for fractional part

public:
    Fixed();                                 // Default constructor
    Fixed(const Fixed& other);               // Copy constructor
    Fixed& operator=(const Fixed& other);    // Copy assignment operator
    ~Fixed();                                // Destructor

    int getRawBits(void) const;              // Getter for raw value
    void setRawBits(int const raw);          // Setter for raw value
};

#endif
