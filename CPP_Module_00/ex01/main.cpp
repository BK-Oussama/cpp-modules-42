
#include <string.h>
#include <string>
#include <iostream>



#include "PhoneBook.hpp"
#include <iostream>

int main()
{
    PhoneBook pb;
    std::string command;

    while (true)
    {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        if (!std::getline(std::cin, command))
        {
            std::cout << "EOF detected. Exiting.\n";
            break;
        }
        if (command == "ADD")
            pb.AddContact();
        else if (command == "SEARCH")
            pb.SearchContacts();
        else if (command == "EXIT")
            break;
    }
    
    return (0);
}
