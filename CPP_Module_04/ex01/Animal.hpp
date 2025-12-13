
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
protected:
    std::string m_type;

public:
    Animal();
    Animal(const Animal &copy);
    Animal &operator=(const Animal &other);
    virtual ~Animal();

    std::string getType() const;
    virtual void makeSound() const;
};

#endif
