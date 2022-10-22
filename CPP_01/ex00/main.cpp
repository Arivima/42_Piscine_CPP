# include "ex00.hpp"

int main(int ac, char **av)
{
    system("clear");
    if (ac != 1 || av[1])
        std::cout << RED"Wrong input. Please launch [" << av[0] << "] without arguments." RESET << std::endl;
    else
    {
    std::cout << CYAN"---------" RESET << std::endl;
        std::cout << BOLDCYAN"Welcome to [" << av[0] << "]." RESET << std::endl;
        std::cout << CYAN "Key:"<< YELLOW " ftRandomChump"<< MAGENTA " ftNewZombie"<<  std::endl;
        ftZombie();
    }
    return ftExit(av[0], EXIT_SUCCESS);;
}

int ftExit(char *name, int status)
{
    std::cout << CYAN"\nExiting [" << name << "]." RESET << std::endl;
    std::cout << BOLDCYAN"Bye Bye." RESET << std::endl;
    std::cout << CYAN"---------" RESET << std::endl;
    return status;
}

int ftZombie(void)
{
    std::cout << CYAN"---------" RESET << std::endl;
    ftRandomChump("George");

    std::cout << CYAN"---------" RESET << std::endl;
    Zombie *mynewzombie = nullptr;
    mynewzombie = ftNewZombie("Francis");
    mynewzombie->ftAnnounce();
    delete mynewzombie;

    std::cout << CYAN"---------" RESET << std::endl;
    delete ftNewZombie("Henry");
    return 0;
}
