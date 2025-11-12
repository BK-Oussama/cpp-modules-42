#include "Intern.hpp"
#include <iostream>
#include <cstring> 



Intern::Intern() {}

Intern::Intern(const Intern &copy)
{
    // Nothing to copy
    (void)copy;
};

Intern &Intern::operator=(const Intern &other)
{
    // Nothing to assign
    (void)other;
    return *this;
};

Intern::~Intern() {};

const char *Intern::UnknownFormException::what() const throw()
{
    return "Intern: Unknown Form Name request.";
}



static AForm *createShrubbery(const std::string &target)
{
    return new ShrubberyCreationForm(target);
};

static AForm *createRobotomy(const std::string &target)
{
    return new RobotomyRequestForm(target);
};

static AForm *createPardon(const std::string &target)
{
    return new PresidentialPardonForm(target);
};


const Intern::FormMapper Intern::m_formMap[] =
{
    {"shrubbery creation", &createShrubbery},
    {"robotomy request", &createRobotomy},
    {"presidential pardon", &createPardon}
};


AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
    AForm *form = NULL;

    int i = 0;
    while (i < 3)
    {
        if (formName == m_formMap[i].formName)
        {
            form = m_formMap[i].func(target);
            break;
        }
        i++;
    }

    if (form == NULL)
    {
        throw UnknownFormException();
    }

    std::cout << "Intern creates " << form->getName() << std::endl;
    return form;
}