
#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("Robotomy Request Form", 72, 45), m_target(target) {};

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("Robotomy Request Form", 72, 45), m_target("default") {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other), m_target(other.m_target) {};

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        m_target = other.m_target;
    }
    return *this;
};

RobotomyRequestForm::~RobotomyRequestForm() {};


#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"


void RobotomyRequestForm::executeAction() const
{
    bool succes = rand() % 2 == 0;
    std::cout << "* _DRILLING_NOISES_ *" << std::endl;
    if (succes)
        std::cout << GREEN << this->m_target << " has been robotomized succesfuly" << RESET << std::endl;
    else
        std::cout << RED << "ROBOTOMY " << m_target << " failed" << RESET << std::endl;
};

