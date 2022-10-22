# include "ex00.hpp"

Zombie*     ftNewZombie(std::string name)
{
    std::cout << MAGENTA <<  std::endl;

    Zombie  *myzombie = new Zombie(name);

    std::cout << RESET << std::endl;
    return myzombie;
}