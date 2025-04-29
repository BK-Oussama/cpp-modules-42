
#include "PhoneBook.hpp"

#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() : NumContact(0), NextIndex(0) {}

void PhoneBook::AddContact()
{
    contacts[NextIndex].SetInfo();
    if (NumContact < 8)
        NumContact++;
    NextIndex = (NextIndex + 1) % 8;
}

std::string formatField(const std::string &str)
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return std::string(10 - str.length(), ' ') + str;
}

void PhoneBook::SearchContacts() const
{

    std::cout << "\n"
              << "|" << std::setw(10) << "Index"
              << "|" << std::setw(10) << "First Name"
              << "|" << std::setw(10) << "Last Name"
              << "|" << std::setw(10) << "Nickname"
              << "|\n";

    std::cout << std::string(45, '-') << "\n";


    int i = 0;
    while (i < 8)
    {
        if (!contacts[i].IsEmpty())
        {

            std::cout << "|" << std::setw(10) << i
                      << "|" << std::setw(10) << formatField(contacts[i].getFirstName())
                      << "|" << std::setw(10) << formatField(contacts[i].getLastName())
                      << "|" << std::setw(10) << formatField(contacts[i].getNickname())
                      << "|\n";
        }
        i++;
    }


    std::string input_index;
    GetInput("Enter Index Of Contact To Display: ", input_index);

    if (input_index.length() != 1 || !isdigit(input_index[0]))
    {
        std::cout << "Invalid input. Please enter a digit between 0 and 7.\n";
        return; // or maybe prompt again till good input or valid index!
    }

    int index = input_index[0] - '0';
    if (index < 0 || index >= 8)
    {
        std::cout << "No contact found at this index.\n";
        return;
    }

    contacts[index].ListContact();
}
