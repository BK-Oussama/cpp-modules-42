#ifndef SEIALIZER_HPP
#define SEIALIZER_HPP

#include <stdint.h>
#include <string>
#include "Data.hpp"


class Serializer
{
private:
    Serializer();
    Serializer(const Serializer &copy);
    Serializer &operator=(const Serializer &other);
    ~Serializer();

public:
    // Takes a pointer and converts it to the unsigned integer type uintptr_t.
    static uintptr_t serialize(Data *ptr);

    // Takes an unsigned integer parameter and converts it to a pointer to Data.
    static Data *deserialize(uintptr_t raw);
};



#endif