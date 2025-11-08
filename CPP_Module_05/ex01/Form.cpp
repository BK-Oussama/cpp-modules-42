

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : m_name("A form"), m_is_signed(false), m_grade_to_sign(150), m_grade_to_execute(150) {};

Form::Form(const std::string &name, int signGrade, int execGrade)
    : m_name(name), m_is_signed(false), m_grade_to_sign(signGrade), m_grade_to_execute(execGrade)
{
    checkGrade(m_grade_to_sign);
    checkGrade(m_grade_to_execute);
};

Form::Form(const Form &copy): m_name(copy.m_name), m_is_signed(copy.m_is_signed),
    m_grade_to_sign(copy.m_grade_to_sign), m_grade_to_execute(copy.m_grade_to_execute) {};



Form &Form::operator=(const Form &other)
{
    // Note: The constant members (_name, _grade_to_sign, _grade_to_execute)
    // CANNOT be reassigned.

    if (this != &other)
        m_is_signed = other.m_is_signed;
    
    return *this;
}


Form::~Form()
{
    std::cout << "Form Destructor called: " << m_name << std::endl;
}


const char *Form::GradeTooHightException::what() const throw()
{
    return "Form: Grade Too High";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Form: Grade to low";
}

void Form::checkGrade(int grade) const
{
    if (grade < 1)
        throw Form::GradeTooHightException();
    if (grade > 150)
        throw Form::GradeTooLowException();
}




const std::string Form::getName() const
{
    return m_name;
}

bool Form::getIsSigned() const
{
    return m_is_signed;
}

int Form::getSignGrade() const
{
    return m_grade_to_sign;
}

int Form::getExecuteGrade() const
{
    return m_grade_to_execute;
            
}



void Form::beSigned(const Bureaucrat& signer)
{
    if (m_is_signed)
    {
        // If already signed, no action is taken.
        std::cout << m_name << " is already signed." << std::endl;
        return ;
    }

    // A lower number is a higher grade. If the signer's grade is numerically higher 
    // than the required sign grade, they are not qualified.
    if (signer.getGrade() > m_grade_to_sign)
    {
        // Throw an exception to inform the caller (Bureaucrat::signForm) of the failure.
        throw Form::GradeTooLowException();
    }
    m_is_signed = true;
}

    
std::ostream& operator<<(std::ostream& os, const Form& f)
{
    os << "Form: " << f.getName() 
       << ", Status: " << std::boolalpha << f.getIsSigned()
       << ", Sign Grade: " << f.getSignGrade()
       << ", Execute Grade: " << f.getExecuteGrade();
    return os;
}