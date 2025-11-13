#include "Base.hpp"
#include <stdexcept>

Base *generate(void)
{
    static bool seeded = false;
    if (!seeded)
    {
        std::srand(std::time(0));
        seeded = true;
    }

    int choice = std::rand() % 4; // 0, 1, or 2
    switch (choice)
    {
    case 0:
        std::cout << "Generated: A" << std::endl;
        return new A();
    case 1:
        std::cout << "Generated: B" << std::endl;
        return new B();
    case 2:
        std::cout << "Generated: C" << std::endl;
        return new C();
    case 3:
        std::cout << "Generated: NULL" << std::endl;
        return NULL;
    default:
        std::cout << "Generated: NULL" << std::endl;
        return NULL;
    }
}

void identify(Base *p)
{
    std::cout << "identify(Base* p): ";

    if (dynamic_cast<A *>(p))
    {
        std::cout << "A" << std::endl;
    }
    else if (dynamic_cast<B *>(p))
    {
        std::cout << "B" << std::endl;
    }
    else if (dynamic_cast<C *>(p))
    {
        std::cout << "C" << std::endl;
    }
    else
    {
        std::cout << "Unknown type or NULL pointer." << std::endl;
    }
}

void identify(Base &p)
{
    std::cout << "identify(Base& p): ";

    try
    {
        (void)dynamic_cast<A &>(p);
        std::cout << "A" << std::endl;
        return;
    }
    catch (const std::bad_cast &e)
    {
    }

    try
    {
        (void)dynamic_cast<B &>(p);
        std::cout << "B" << std::endl;
        return;
    }
    catch (const std::bad_cast &e)
    {
    }

    try
    {
        (void)dynamic_cast<C &>(p);
        std::cout << "C" << std::endl;
        return;
    }
    catch (const std::bad_cast &e)
    {
        std::cout << e.what() << " Unknown type." << std::endl;
    }
}

int main()
{
    Base *ptr = NULL;

    std::cout << "===========================" << std::endl;

    int i = 0;
    while (i < 4)
    {
        ptr = generate();

        std::cout << "--- Test " << i + 1 << " ---" << std::endl;

        identify(ptr);

        identify(*ptr);

        delete ptr;
        std::cout << std::endl;

        i++;

        std::cout << "----------------" << std::endl;
    }

    std::cout << "===========================" << std::endl;
    return 0;
}
