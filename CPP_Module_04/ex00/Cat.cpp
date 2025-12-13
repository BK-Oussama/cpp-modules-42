
#include "Cat.hpp"

Cat::Cat()
{
    m_type = "Cat";
    std::cout << "Cat created\n";
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
    std::cout << "Cat copied\n";
}

Cat &Cat::operator=(const Cat &other)
{
    if (this != &other)
    {
        Animal::operator=(other);
    }
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat destroyed\n";
}

void Cat::makeSound() const
{
    std::cout << "Meow!\n";
}
