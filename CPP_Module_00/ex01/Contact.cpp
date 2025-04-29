
#include "Contact.hpp"
#include <iostream>
#include <cstdlib>


void Contact::SetInfo()
{
    GetInput("Enter first name: ", m_first_name);
    GetInput("Enter last name: ", m_last_name);
    GetInput("Enter nickname: ", m_nickname);
    GetInput("Enter phone number: ", m_phone_number);
    GetInput("Enter darkest secret: ", m_dark_secret);
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

void GetInput(const std::string &prompt, std::string &target)
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
        std::cout << "Field Cannot Be Empty. Please Try Again.\n";
    }
}