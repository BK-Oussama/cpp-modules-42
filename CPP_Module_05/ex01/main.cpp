#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
    try
    {
        Bureaucrat qualified("Mr. Qualified", 5);
        Bureaucrat unqualified("Ms. Unqualified", 100);
        Form easyForm("Easy Approval Form", 50, 50);

        std::cout << "--- Initial Status ---" << std::endl;
        std::cout << qualified << std::endl;
        std::cout << unqualified << std::endl;
        std::cout << easyForm << std::endl;
        std::cout << std::endl
                  << "------------------------------------\n\n";

        // ---  Successful Signing ---
        qualified.signForm(easyForm);
        std::cout << easyForm << std::endl;
        std::cout << std::endl
                  << "------------------------------------\n\n";

        // --- Unsuccessful Signing
        unqualified.signForm(easyForm);

        Form hardForm("Hard Permit", 10, 10); // Requires Grade 10 to sign
        std::cout << hardForm << std::endl;

        unqualified.signForm(hardForm);
        std::cout << std::endl
                  << "------------------------------------\n\n";

        // --- Successful Signing ---
        qualified.signForm(hardForm);
        std::cout << hardForm << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Caught unexpected exception in main: " << e.what() << std::endl;
    }

    return 0;
}