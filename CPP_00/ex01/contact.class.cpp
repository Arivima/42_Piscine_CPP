#include <iostream>
# include "contact.class.hpp"

Contact::Contact(void) // constructor
{
    // std::cout << "ContactConstructor called" << std::endl;
    return;
}

Contact::~Contact(void) // destructor
{
    // std::cout << "ContactDestructor called" << std::endl;
    return;
}

// setters
int    Contact::ftSetFieldStr(int FieldID, std::string input)
{
    std::string *fieldp = nullptr;

    switch (FieldID) 
    {
        case Contact::eFirstName: fieldp = &this->FirstName; break;
        case Contact::eLastName: fieldp = &this->LastName; break;
        case Contact::eNickname: fieldp = &this->Nickname; break;
        case Contact::ePhoneNumber: fieldp = &this->PhoneNumber; break;
        case Contact::eDarkestSecret: fieldp = &this->DarkestSecret; break;
        default: std::cerr << "Error: ftSetFieldStr " << std::endl; return 1;
    }
    if (!fieldp)
    {
        std::cerr << "Error: ftSetFieldStr " << std::endl;
        return 1;
    }
    (*fieldp).assign(input);
    return 0;
}

int    Contact::ftResetContact(void)
{
    this->FirstName.erase(0);
    this->LastName.erase(0);
    this->Nickname.erase(0);
    this->PhoneNumber.erase(0);
    this->DarkestSecret.erase(0);
    return 0;
}

// getters
std::string Contact::ftGetFieldStr(int FieldID) const
{
    std::string FieldStr;

    switch (FieldID) 
    {
        case Contact::eFirstName: FieldStr = this->FirstName; break;
        case Contact::eLastName: FieldStr = this->LastName; break;
        case Contact::eNickname: FieldStr = this->Nickname; break;
        case Contact::ePhoneNumber: FieldStr = this->PhoneNumber; break;
        case Contact::eDarkestSecret: FieldStr = this->DarkestSecret; break;
        default: std::cerr << "Error: ftGetFieldStr " << std::endl; return "";
    }
    return FieldStr;
}

std::string Contact::ftGetFieldName(int FieldID) const
{
    std::string FieldName;

    switch (FieldID) 
    {
        case Contact::eFirstName: FieldName.assign("First Name"); break;
        case Contact::eLastName: FieldName.assign("Last Name"); break;
        case Contact::eNickname: FieldName.assign("Nickname"); break;
        case Contact::ePhoneNumber: FieldName.assign("Phone Number"); break;
        case Contact::eDarkestSecret: FieldName.assign("Darkest Secret"); break;
        default: std::cerr << "Error: ftGetFieldName " << std::endl; return "";
    }
    return FieldName;
}

// printers
int        Contact::ftPrintContact() const
{
    std::cout << YELLOW "---------------------------------------------" << std::endl;
    std::cout <<  "> Printing all details of this contact"  << std::endl;
    for (int i = this->eFirstName; i <= this->eDarkestSecret; i++)
    {
        std::string FieldName = this->ftGetFieldName(i);
        std::string FieldStr = this->ftGetFieldStr(i);
        if (FieldName.empty() == true || FieldStr.empty() == true)
            return 1;
        std::cout << FieldName << "\t: " << FieldStr << std::endl;
    }
    std::cout << "---------------------------------------------" RESET << std::endl;
    return 0;
}
