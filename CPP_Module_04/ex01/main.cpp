#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    std::cout << "=== Deep Copy Test ===" << std::endl;

    {
        Dog basic;
        {
            Dog tmp = basic;
        }
    }

    
    std::cout << "\n=== Polymorphic Array Test ===" << std::endl;
    
    const int size = 2;
    Animal *animals[size];

    int i = 0;
    while (i < size / 2)
    {
        animals[i] = new Dog();
        i++;
    }

    while (i < size)
    {
        animals[i] = new Cat();
        i++;
    }

    i = 0;
    while (i < size)
    {
        delete animals[i];
        i++;
    }

    return 0;
}
