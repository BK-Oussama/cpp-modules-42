
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>


ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target):
    AForm("Shrubbery Creation Form", 145, 137), m_target(target) {};


ShrubberyCreationForm::ShrubberyCreationForm():
    AForm("Shrubbery Creation Form", 145, 137), m_target("default") {};

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other):
    AForm(other), m_target(other.m_target) {};


ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other) {
        AForm::operator=(other); 
        m_target = other.m_target;
    }
    return *this;
};

ShrubberyCreationForm::~ShrubberyCreationForm(){};


void ShrubberyCreationForm::executeAction() const
{
    std::string filename = m_target + "_shrubbery";
    
    std::ofstream of(filename.c_str());

    if (!of.is_open()) {
        std::cerr << "Error: Could not create file " << filename << std::endl;
        return;
    }

    of << "       /\\      " << std::endl;
    of << "      /\\*\\     " << std::endl;
    of << "     /\\o\\*\\    " << std::endl;
    of << "    /\\/\\/\\/\\   " << std::endl;
    of << "   /\\*\\/\\o\\*\\  " << std::endl;
    of << "  /\\o\\/\\/\\/\\/\\ " << std::endl;
    of << " /\\*\\/\\o\\*\\/\\/\\" << std::endl;
    of << "       | |       " << std::endl;
    of << "       | |       " << std::endl;
    of << "       | |       " << std::endl;
    of << "      // \\\\       " << std::endl;

    
    of.close();

}