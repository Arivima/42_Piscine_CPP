# include "colors.hpp"
# include "sed.class.hpp"

# include <iostream>
# include <string>

void    ftEnter(char **av);
int     ftExit(std::string name, int status);

int main(int ac, char **av)
{
    system("clear");
    if (ac == 4)
    {
        ftEnter(av);
        Sed myFtSed;
        if (myFtSed.ftSed(av[1], av[2], av[3]) == ERR)
            return ftExit(av[0], EXIT_FAILURE);;
    }
    else
    {
        std::cout << RED"Wrong input.\nPlease launch [" << av[0] << "] with three parameters in the following order: a filename and two strings, s1 and s2." RESET << std::endl;
        return ftExit(av[0], EXIT_FAILURE);;
    }
    return ftExit(av[0], EXIT_SUCCESS);;
}
      



void ftEnter(char **av)
{
    std::cout << CYAN"---------" RESET << std::endl;
    std::cout << BOLDCYAN"Welcome to [" << av[0] << "]." RESET << std::endl;
    std::cout << CYAN ">>fileName \"" << av[1] << "\" | " ;
    std::cout <<  "s1 [" << av[2] << "] => " ;
    std::cout <<  "s2 [" << av[3] << "]." RESET << std::endl;
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
