# include <iostream>
# include "phonebook.class.hpp"

int PhoneBook::ftSearch(void)
{
    std::cout <<  "---------------------------------------------" << std::endl;
    std::cout << GREEN "> We will search a contact now" RESET << std::endl;
    ftPrintPhoneBook();
    while (1)
    {
        this->input.erase(0);
        std::cout << CYAN "> Please enter the index of the contact to display" RESET << std::endl << ">>";
        std::getline(std::cin, this->input, '\n');

        if (std::cin.eof() == true)
            return 1;
        else if (this->input.empty() == true)
        {
            std::cout << RED"This field has to be filled" RESET << std::endl;
            continue;
        }
        else if (input.size() != 1 || this->input[0] < '0' || this->input[0] > '7')
            std::cout << RED "Wrong instruction, please try again.\n" RESET << std::endl;
        else
        {
            int index = std::stoi(input, 0, 10);
            ftPrintContact(index);
            break;
        }
    }
    return 0;
}

std::string  PhoneBook::ftFormatStr(std::string str) const
{
    std::string newStr;

    if (str.size() > 10)
    {
        newStr = str.substr(0, 9);
        newStr.push_back('.');
    }
    else if (str.size() < 10)
    {
        newStr.assign(10 - str.size(), ' ');
        newStr.append(str);
    }
    else
        newStr.assign(str);

    return newStr;
}

// clear
int PhoneBook::ftPrintPhoneBook(void) const
{
    std::cout << YELLOW "---------------------------------------------" << std::endl;
    std::cout << "> Printing all contacts in MyPhoneBook"  << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "|     Index|" << "First Name|" << " Last Name|" << "  Nickname|" <<std::endl;
    std::cout << "|----------|----------|----------|----------|" << std::endl;

    for (int index = 0; index < 8; index++)
    {
        Contact thisContact = this->ContactEntry[index];

        std::cout << "|         " << index;
        std::cout << "|" << ftFormatStr(thisContact.ftGetFieldStr(thisContact.eFirstName));
        std::cout << "|" << ftFormatStr(thisContact.ftGetFieldStr(thisContact.eLastName));
        std::cout << "|" << ftFormatStr(thisContact.ftGetFieldStr(thisContact.eNickname));
        std::cout << "|" << std::endl;

    }
    std::cout << "---------------------------------------------" RESET << std::endl;
    return 0;
}

int PhoneBook::ftPrintContact(int index) const
{
    Contact     thisContact = this->ContactEntry[index];
    std::string FirstName = thisContact.ftGetFieldStr(thisContact.eFirstName);

    std::cout << YELLOW "Index [" << index << "]" RESET << std::endl;
    if (FirstName.empty() == false)
        thisContact.ftPrintContact();
    else
        std::cout << RED ">> Not contact registered yet at this index" RESET << std::endl;
    return 0;
}