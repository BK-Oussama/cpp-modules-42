#include "Bureaucrat.hpp"
#include <iostream>

int main()
{

    try
    {
        Bureaucrat A("BK", 3);
        std::cout << A;
        A.increment_grade();
        std::cout << A;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Bureaucrat A("CR", 150);
        std::cout << A;
        A.decrement_grade();
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    // std::cout << false << "now we print --" << true << std::endl;

}