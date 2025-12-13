#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "=== Valid Polymorphism ===\n";

    const Animal *animal_1 = new Dog();
    const Animal *animal_2 = new Cat();

    std::cout << "animal_1 type: " << animal_1->getType() << std::endl;
    std::cout << "animal_2 type: " << animal_2->getType() << std::endl;

    animal_1->makeSound();
    animal_2->makeSound();

    delete animal_1;
    delete animal_2;



    std::cout << "\n=== Invalid Polymorphism ===\n";
    const WrongAnimal *wrong = new WrongCat();

    std::cout << "wrong type: " << wrong->getType() << std::endl;
    wrong->makeSound();

    delete wrong;

    return 0;
}
