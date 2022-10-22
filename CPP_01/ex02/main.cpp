# include "colors.hpp"

# include <iostream>
# include <string>

int     ftZombie(void);
void    ftEnter(std::string name);
int     ftExit(std::string name, int status);

int main(int ac, char **av)
{
    system("clear");
    if (ac == 1)
    {
        ftEnter(av[0]);
        ftZombie();
    }
    else
    {
        std::cout << RED"Wrong input.\nPlease launch [" << av[0] << "] with no arguments." RESET << std::endl;
        return ftExit(av[0], EXIT_FAILURE);;
    }
    return ftExit(av[0], EXIT_SUCCESS);;
}

int ftZombie(void)
{
    std::string string("HI THIS IS BRAIN");
    std::string *stringPTR = &string;
    std::string &stringREF = string;

    std::cout << "std::string string(\"HI THIS IS BRAIN\");" << std::endl;
    std::cout << "std::string *stringPTR = &string;" << std::endl;
    std::cout << "std::string &stringREF = string;" << std::endl;
    std::cout << std::endl;

    std::cout << "The memory address of the string variable.\t| &string\t| " << &string << std::endl;
    std::cout << "The memory address held by stringPTR\t\t| stringPTR\t| " << stringPTR << std::endl;
    std::cout << "The memory address held by stringREF\t\t| &stringREF\t| " << &stringREF << std::endl;
    std::cout << std::endl;

    std::cout << "The value of the string variable.\t\t| string\t| " << string << std::endl;
    std::cout << "The value pointed to by stringPTR.\t\t| stringPTR\t| " << *stringPTR << std::endl;
    std::cout << "The value pointed to by stringREF.\t\t| stringREF\t| " << stringREF << std::endl;

    return 0;
}

void ftEnter(std::string name)
{
    std::cout << CYAN"---------" RESET << std::endl;
    std::cout << BOLDCYAN"Welcome to [" << name << "]." RESET << std::endl;
    std::cout << CYAN"---------" RESET << std::endl;    
}

int ftExit(std::string name, int status)
{
    std::cout << CYAN"---------" RESET << std::endl;
    std::cout << CYAN"Exiting [" << name << "]." RESET << std::endl;
    std::cout << BOLDCYAN"Bye Bye." RESET << std::endl;
    std::cout << CYAN"---------" RESET << std::endl;
    return status;
}
