# include "colors.hpp"
# include "weapon.class.hpp"
# include "humanA.class.hpp"
# include "humanB.class.hpp"

# include <iostream>
# include <string>

int     ftExec(void);
void    ftEnter(std::string name);
int     ftExit(std::string name, int status);

int main(int ac, char **av)
{
    system("clear");
    if (ac == 1)
    {
        ftEnter(av[0]);
        ftExec();
    }
    else
    {
        std::cout << RED"Wrong input.\nPlease launch [" << av[0] << "] with no arguments." RESET << std::endl;
        return ftExit(av[0], EXIT_FAILURE);;
    }
    return ftExit(av[0], EXIT_SUCCESS);;
}

int ftExec(void)
{
    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.ftAttack();
        club.ftSetType("some other type of club");
        bob.ftAttack();
    }
    std::cout << CYAN"---------" RESET << std::endl;
    {
        Weapon club = Weapon("crude spiked club");
        HumanB jim("Jim");
        jim.ftSetWeapon(club);
        jim.ftAttack();
        club.ftSetType("some other type of club");
        jim.ftAttack();
    }
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
