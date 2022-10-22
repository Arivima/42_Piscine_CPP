# include <iostream>
# include <string>
# include "phonebook.class.hpp"
# include "contact.class.hpp"
# include "colors.hpp"

int     mainLoop(void);
int     ftExit(void);



int main(int ac, char **av)
{
    system("clear");
    if (ac != 1 || av[1])
        std::cout << RED"Wrong input. Please launch MyPhoneBook without arguments." RESET << std::endl;
    else
        mainLoop();
    ftExit();  
    return 0;
}

int     mainLoop(void)
{
    PhoneBook myphonebook;

    std::cout << BOLDCYAN"Welcome to MyPhoneBook." RESET << std::endl;
    while (std::cin.eof() == false)
    {
        std::cout << CYAN "---------------------------------------------"  << std::endl;
        std::cout << "Commands available:" << std::endl;
        std::cout << "   1.Type \"ADD\" to add a contact." << std::endl;
        std::cout << "   2.Type \"SEARCH\" to search a contact." << std::endl;
        std::cout << "   3.Type \"EXIT\" to exit MyPhoneBook." << std::endl;
        std::cout << "---------------------------------------------" RESET  << std::endl;

        myphonebook.input.erase(0);
        std::cout << CYAN"\nPlease enter a command" RESET << std::endl << ">>";
        std::getline(std::cin, myphonebook.input, '\n');

        system("clear");
        std::cout << "You entered [" CYAN << myphonebook.input << RESET "].\n" << std::endl;
        if (std::cin.eof() == true)
            return 0;
        else if (myphonebook.input.compare("ADD") == 0)
            myphonebook.ftAdd();
        else if (myphonebook.input.compare("SEARCH") == 0)
            myphonebook.ftSearch();
        else if (myphonebook.input.compare("EXIT") == 0)
            return 0;
        else if (myphonebook.input.empty() == true)
            std::cout << "> " << RED"You must enter a command." RESET << std::endl << "Remember that instructions are case sensitive." << std::endl;
        else
            std::cout << "> " << RED"Wrong instruction, please try again." RESET << std::endl << "Remember that instructions are case sensitive." << std::endl;
    }
    return 0;
}

int ftExit()
{
    std::cout << BOLDYELLOW"\nExiting MyPhoneBook." RESET << std::endl;
    std::cout << RED"! MyPhoneBook records will be cleared now." RESET << std::endl;
    std::cout << BOLDYELLOW"Bye Bye." RESET << std::endl;
    return 0;
}



