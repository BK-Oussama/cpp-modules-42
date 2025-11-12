#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    std::srand(std::time(NULL));

    AForm *shrubbery = NULL;
    AForm *robotomy = NULL;
    AForm *pardon = NULL;

    try
    {
        // all permsions
        Bureaucrat cidna("Cidna", 1);

        // Grade 40: Can sign everything, can execute Robotomy/Shrubbery
        Bureaucrat executor("Standard Executor", 40);

        // Grade 140: Can only sign/execute Shrubbery
        Bureaucrat signer("Low Level Signer", 140);

        std::cout << cidna << executor << signer;

        std::cout << "---------------------------------\n\n";
        shrubbery = new ShrubberyCreationForm("Home_Garden");
        robotomy = new RobotomyRequestForm("Bender");
        pardon = new PresidentialPardonForm("Zaphod");

        std::cout << "---------- FORM CREATION  ----------\n";
        std::cout << *shrubbery << std::endl;
        std::cout << *robotomy << std::endl;
        std::cout << *pardon << std::endl;
        std::cout << "------------------------------------\n\n";

        // Failure Case A: Execution Grade Too Low
        signer.signForm(*shrubbery); // Signer (140) - Shrubbery sign grade (145)
        std::cout << *shrubbery << std::endl;
        signer.executeForm(*shrubbery); // Shrubbery exec grade 137. Signer's exc grade (140).

        std::cout << "\n---------- Form Not Signed -----------\n";

        cidna.executeForm(*robotomy);

        std::cout << "----------------------------------------\n\n";

        // TEST POLYMORPHIC SUCCESS (Using the single executor: cidna)
        std::cout << "------- TEST POLYMORPHIC -------\n";

        cidna.signForm(*robotomy);
        cidna.signForm(*pardon);

        cidna.executeForm(*shrubbery);

        cidna.executeForm(*robotomy);
        std::cout << "\n";
        cidna.executeForm(*robotomy); // Run twice to see random result

        std::cout << "\n// --- Execute Pardon (High Grade Check) ---\n";
        signer.executeForm(*pardon);

        std::cout << "------------------------------------\n\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << "\n"
                  << e.what() << std::endl;
    }

    delete shrubbery;
    delete robotomy;
    delete pardon;

    return 0;
}