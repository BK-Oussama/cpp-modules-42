

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact{

private:
    std::string m_first_name;
    std::string m_last_name;
    std::string m_nickname;
    std::string m_dark_secret;
    std::string m_phone_number;

public:
    void SetInfo();
    void ListContact() const;
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickname() const;
    bool IsEmpty() const;

};

void GetInput(const std::string &prompt, std::string &target);

#endif