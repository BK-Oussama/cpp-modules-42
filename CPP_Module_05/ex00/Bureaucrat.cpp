

#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() : m_name(0), m_grade(150)
{
    std::cout << "Default constructor called" << std::endl;
};

Bureaucrat::Bureaucrat(std::string name, int grade) : m_name(name), m_grade(grade)
{

    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
};

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : m_name(copy.m_name), m_grade(copy.m_grade)
{
    std::cout << "Copy constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        // We CANNOT assign m_name because it is const.
        m_grade = other.m_grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Destructor called" << std::endl;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade Too High Exception: Grade cannot be higher than 1");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade Too Low Exception: Grade cannot be lower than 150");
}

void Bureaucrat::check_grade(int grade) const
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

std::string Bureaucrat::getName() const
{
    return m_name;
}

int Bureaucrat::getGrade() const
{
    return m_grade;
}

void Bureaucrat::increment_grade()
{
    check_grade(m_grade - 1);
    m_grade--;
}

void Bureaucrat::decrement_grade()
{
    check_grade(m_grade + 1);
    m_grade++;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b)
{
    out << b.getName() << ", bureaucrat grade " << b.getGrade() << "." << std::endl;
    return out;
}
