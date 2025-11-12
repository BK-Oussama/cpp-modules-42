#ifndef INTERN_HPP
#define INTERN_HPP

#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

class Intern
{

private:
    typedef AForm *(*FormCreationFunc)(const std::string &target);

    struct FormMapper
    {
        const char *formName;
        FormCreationFunc func;
    };

    static const FormMapper m_formMap[3];

public:
    Intern();
    Intern(const Intern &other);
    Intern &operator=(const Intern &other);
    ~Intern();

    AForm *makeForm(const std::string &formName, const std::string &target);

    class UnknownFormException : public std::exception
    {
        public:
            virtual const char *what() const throw();
    };
};

#endif