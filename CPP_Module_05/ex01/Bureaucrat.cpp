

#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() : m_name(0), m_grade(150)
{
    std::cout << "Default constructor called" << std::endl;
};


Bureaucrat::Bureaucrat(std::string name, int grade) : m_name(name), m_grade(grade)
{
    if (m_grade < 0 ) 
        throw()

    if (m_grade > 150)
        throw()
};


Bureaucrat::Bureaucrat(const Bureaucrat &copy) : m_name(copy.m_name),m_grade(copy.m_grade)
{
    std::cout << "Copy constructor called" << std::endl;
}


Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        m_name = other.m_name;
        m_grade = other.m_grade;
    }
    return *this;
}



std::string Bureaucrat::getName() const
{

}

int Bureaucrat::getGrade() const
{

}
    
void Bureaucrat::increment_grade()
{

}

void Bureaucrat::decrement_grade()
{

}