# include "ex01.hpp"

int main(int ac, char **av)
{
    system("clear");
    if (ac != 3 || ftIsStrDigit(av[1]) == 0)
        std::cout << RED"Wrong input.\nPlease launch [" << av[0] << "] with 2 arguments [N][Name].\nN should be a positive integer > 0." RESET << std::endl;
    else
    {
        int N = std::stoi(av[1]);
        std::string name = av[2];
        std::cout << CYAN"---------" RESET << std::endl;
        std::cout << BOLDCYAN"Welcome to [" << av[0] << "]." RESET << std::endl;
        std::cout << BOLDCYAN">>Building a horde of " << N << " Zombies named " << name << RESET << std::endl;
        std::cout << CYAN"---------" RESET << std::endl;
        ftZombie(N, name);
    }
    return ftExit(av[0], EXIT_SUCCESS);;
}

int ftZombie(int N, std::string name)
{
    // create Horde
    Zombie *myZombieHorde;
    myZombieHorde = ftZombieHorde(N, name);
    
    // announce Horde
    for (int i = 0; i < N; i++)
        myZombieHorde[i].ftAnnounce();

    // delete Horde
    delete[] myZombieHorde;

    return 0;
}

int ftExit(char *name, int status)
{
    std::cout << CYAN"\n---------" RESET << std::endl;
    std::cout << CYAN"Exiting [" << name << "]." RESET << std::endl;
    std::cout << BOLDCYAN"Bye Bye." RESET << std::endl;
    std::cout << CYAN"---------" RESET << std::endl;
    return status;
}

bool ftIsStrDigit(std::string str)
{
    if (str[0] == '0' && !str[1])
        return 0;
    for (int i = 0; str[i]; i++)
    {
        if (std::isdigit(str[i]) == 0)
            return 0;
    }
    return 1;
}
