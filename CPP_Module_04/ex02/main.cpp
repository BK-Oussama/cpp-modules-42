
#include "Dog.hpp"
#include "Cat.hpp"

// int main()
// {

//     const Animal *j = new Dog();
//     const Animal *i = new Cat();

//     delete j;
//     delete i;

//     Dog dog1;
//     dog1.makeSound();

//     Dog dog2 = dog1; // Should perform a deep copy

//     return 0;
// }



#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    std::cout << "=== Abstract Class Test ===" << std::endl;

    // Animal test; // can't instantiate abstract class

    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << "Dog says: ";
    dog->makeSound();

    std::cout << "\n";

    std::cout << "Cat says: ";
    cat->makeSound();

    delete dog;
    delete cat;

    return 0;
}
