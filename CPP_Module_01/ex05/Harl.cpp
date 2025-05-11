#include "Harl.hpp"

void Harl::debug(void)
{
    std::cout << "[Debug]\tthis is a DEBUG message" << std::endl;
}

void Harl::info(void)
{
    std::cout << "[Info]\tthis is an INFO message" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "[Warning]\tthis is a WARNING message" << std::endl;
}

void Harl::error(void)
{
    std::cout << "[Error]\tthis is an ERROR message" << std::endl;
}

void Harl::complain(std::string level)
{
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    // functions is an array of pointers to member functions of the class Harl
    void (Harl::*functions[])(void) = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error};

    int index = -1;
    int i = 0;
    while (i < 4)
    {
        if (levels[i] == level)
        {
            index = i;
            break;
        }
        i++;
    }

    switch (index)
    {
    case 0:
        (this->*functions[0])();
        break;
    case 1:
        (this->*functions[1])();
        break;
    case 2:
        (this->*functions[2])();
        break;
    case 3:
        (this->*functions[3])();
        break;
    default:
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}
