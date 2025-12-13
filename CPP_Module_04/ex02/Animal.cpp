
#include "Animal.hpp"

Animal::Animal() : type("Animal") {
    std::cout << "Animal constructed\n";
}

Animal::~Animal() {
    std::cout << "Animal destroyed\n";
}

Animal::Animal(const Animal &other) {
    type = other.type;
}

Animal &Animal::operator=(const Animal &other) {
    if (this != &other)
        type = other.type;
    return *this;
}

std::string Animal::getType() const {
    return type;
}
