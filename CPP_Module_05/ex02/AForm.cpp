

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : m_name("A form"), m_is_signed(false), m_grade_to_sign(150), m_grade_to_execute(150) {};

AForm::AForm(const std::string &name, int signGrade, int execGrade)
    : m_name(name), m_is_signed(false), m_grade_to_sign(signGrade), m_grade_to_execute(execGrade)
{
    checkGrade(m_grade_to_sign);
    checkGrade(m_grade_to_execute);
};

AForm::AForm(const AForm &copy) : m_name(copy.m_name), m_is_signed(copy.m_is_signed),
                                  m_grade_to_sign(copy.m_grade_to_sign), m_grade_to_execute(copy.m_grade_to_execute) {};

AForm &AForm::operator=(const AForm &other)
{
    // Note: The constant members (_name, _grade_to_sign, _grade_to_execute)
    // CANNOT be reassigned.

    if (this != &other)
        m_is_signed = other.m_is_signed;

    return *this;
}

AForm::~AForm()
{
    std::cout << "Form Destructor called: " << m_name << std::endl;
}

const char *AForm::GradeTooHightException::what() const throw()
{
    return "AForm::GradeTooHighException: Grade must be 1 or higher.";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "AForm::GradeTooLowException: Grade must be 150 or lower.";
}

void AForm::checkGrade(int grade) const
{
    if (grade < 1)
        throw AForm::GradeTooHightException();
    if (grade > 150)
        throw AForm::GradeTooLowException();
}

const std::string AForm::getName() const
{
    return m_name;
}

bool AForm::getIsSigned() const
{
    return m_is_signed;
}

int AForm::getSignGrade() const
{
    return m_grade_to_sign;
}

int AForm::getExecuteGrade() const
{
    return m_grade_to_execute;
}

void AForm::beSigned(const Bureaucrat &signer)
{
    if (m_is_signed)
    {
        std::cout << m_name << " is already signed." << std::endl;
        return;
    }

    // A lower number is a higher grade. If the signer's grade is numerically higher
    // than the required sign grade, they are not qualified.
    if (signer.getGrade() > m_grade_to_sign)
    {
        throw AForm::GradeTooLowException();
    }
    m_is_signed = true;
}

void AForm::execute(Bureaucrat const &executor) const
{
    if (m_is_signed == false)
    {
        throw std::logic_error("AFormException: Cannot execute, form is not signed.");
    }

    if (executor.getGrade() > m_grade_to_execute)
    {
        throw AForm::GradeTooLowException();
    }

    executeAction();
}

std::ostream &operator<<(std::ostream &os, const AForm &f)
{
    std::string status;
    if (f.getIsSigned())
        status = "signed";
    else
        status = "not signed";


        
    os << "Form: " << f.getName()
       << ", Status: " << status
       << ", Sign Grade: " << f.getSignGrade()
       << ", Execute Grade: " << f.getExecuteGrade();
    return os;
}