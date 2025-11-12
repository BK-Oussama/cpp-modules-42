
#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
    const std::string m_name;
    bool m_is_signed;
    const int m_grade_to_sign;
    const int m_grade_to_execute;

    void checkGrade(int garde) const;

public:
    AForm();
    AForm(const std::string &name, int signGrade, int execGrade);
    AForm(const AForm &copy);
    AForm &operator=(const AForm &other);

    virtual ~AForm();

    class GradeTooHightException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    const std::string getName() const;
    bool getIsSigned() const;
    int getSignGrade() const;
    int getExecuteGrade() const;

    void beSigned(const Bureaucrat &signer);

    void execute(Bureaucrat const &executor) const;
    virtual void executeAction() const = 0;
};

std::ostream &operator<<(std::ostream &os, const AForm &f);

#endif
