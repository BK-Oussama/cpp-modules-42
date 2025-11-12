
#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

#include <string>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{

private:
    std::string m_target;

    PresidentialPardonForm();

public:
    PresidentialPardonForm(const std::string &target);

    PresidentialPardonForm(const PresidentialPardonForm &other);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
    virtual ~PresidentialPardonForm();

    virtual void executeAction() const;
};

#endif  