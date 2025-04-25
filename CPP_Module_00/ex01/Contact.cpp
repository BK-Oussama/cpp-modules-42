
#include "Contact.hpp"
#include <iostream>
#include <cstdlib>

void getInput(const std::string &prompt, std::string &target)
{
    while (true)
    {
        std::cout << prompt;
        if (!std::getline(std::cin, target))
        {
            std::cout << "\n EOF. Exiting...\n";
            exit(EXIT_FAILURE);
        }
        if (!target.empty())
            return ;
        std::cout << "Field cannot be empty. Please try again.\n";
    }
}

void Contact::SetInfo()
{
    getInput("Enter first name: ", m_first_name);
    getInput("Enter last name: ", m_last_name);
    getInput("Enter nickname: ", m_nickname);
    getInput("Enter phone number: ", m_phone_number);
    getInput("Enter darkest secret: ", m_dark_secret);
}

void Contact::ListContact() const
{
    std::cout << "First Name: " << m_first_name << "\n";
    std::cout << "Last Name: " << m_last_name << "\n";
    std::cout << "Nickname: " << m_nickname << "\n";
    std::cout << "Phone Number: " << m_phone_number << "\n";
    std::cout << "Darkest Secret: " << m_dark_secret << "\n";
}

std::string Contact::getFirstName() const
{
    return m_first_name;
}

std::string Contact::getLastName() const
{
    return m_last_name;
}

std::string Contact::getNickname() const
{
    return m_nickname;
}

bool Contact::IsEmpty() const
{
    return m_first_name.empty();
}