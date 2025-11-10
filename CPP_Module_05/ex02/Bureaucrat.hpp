
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <stdexcept>
#include <string>

#include "AForm.hpp"
class AForm;

class Bureaucrat
{
private:
    const std::string m_name;
    int m_grade;

public:
    Bureaucrat();
    Bureaucrat(std::string name, int grade);
    Bureaucrat(const Bureaucrat &copy);
    Bureaucrat &operator=(const Bureaucrat &other);
    ~Bureaucrat();

    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    void check_grade(int grade) const;
    std::string getName() const;
    int getGrade() const;

    void increment_grade();
    void decrement_grade();

    void signForm(AForm& form) const;

    void executeForm(AForm const & form) const;


};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);

#endif