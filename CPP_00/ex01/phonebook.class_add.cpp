#include <iostream>
# include "phonebook.class.hpp"


int    PhoneBook::ftAdd(void)
{
    
    if (this->ftAddContact(this->index % 8) == 1)
        return 1;
    this->index++;
    if (this->index >= 32)
        this->index = 0;
    return 0;
}

int PhoneBook::ftAddContact(int index)
{
    Contact     thisContact = this->ContactEntry[index];
    int         FieldID     = 0;

    std::cout << GREEN "> We will save a new contact now" RESET << std::endl;
    while (FieldID < 5)
    {
        std::string FieldName = thisContact.ftGetFieldName(FieldID);
        if (FieldName.empty() == true)
            return 1;
    
        this->input.erase(0);
        std::cout << "\nPlease add contact " CYAN << FieldName << RESET << std::endl << ">>";
        std::getline(std::cin, this->input, '\n');

        if (std::cin.eof() == true)
            return 1;
        else if (this->input.empty() == true)
            std::cout << RED"This field has to be filled" RESET << std::endl;
        else
        {
            if (thisContact.ftSetFieldStr(FieldID, input) == 1)
                return 1;
            FieldID++; 
        }

    }
    system("clear");
    this->ContactEntry[index].ftResetContact();
    this->ContactEntry[index] = thisContact;
    std::cout << GREEN "Contact Registered." RESET << std::endl;
    return 0;
}
