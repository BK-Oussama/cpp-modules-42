#ifndef PHONEBOOK
#define PHONEBOOK

#include "Contact.hpp"

class PhoneBook
{
private:
    Contact contacts[8];
    int NumContact;
    int NextIndex;

public:
    PhoneBook();
    void AddContact();
    void SearchContacts() const;
};

#endif
