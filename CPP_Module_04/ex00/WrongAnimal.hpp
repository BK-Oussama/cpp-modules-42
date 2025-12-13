#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
protected:
    std::string m_type;

public:
    WrongAnimal();
    ~WrongAnimal();
    
    WrongAnimal(const WrongAnimal &copy);
    WrongAnimal &operator=(const WrongAnimal &other);

    std::string getType() const;
    void makeSound() const;
};

#endif
