#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>
#include <iomanip>

int main()
{
    srand(time(NULL));
    Intern intern;
    AForm *form1 = NULL;
    AForm *form2 = NULL;

    Bureaucrat boss("Boss", 5);

    try
    {
        form1 = intern.makeForm("robotomy request", "Marvin");
        boss.signForm(*form1);
        boss.executeForm(*form1);
    }
    catch (std::exception &e)
    {
        std::cerr << "Test 1 Failed: " << e.what() << std::endl;
    }


    std::cout << "\n------------------------------\n";
    
    try
    {
        form2 = intern.makeForm("visa application", "Mars");
    }
    catch (const Intern::UnknownFormException &e)
    {
        std::cerr << "Caught Expected Error: " << e.what() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Caught Unexpected Error: " << e.what() << std::endl;
    }

    std::cout << "\n------------------------------\n";

    delete form1;

    return 0;
}