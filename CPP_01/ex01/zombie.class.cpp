# include "zombie.class.hpp"

            Zombie::Zombie(void) : name(std::string())// constructor
{
    std::cout << GREEN "\t\t: ........ Momma !"<< "\t[Constructor]" RESET << std::endl;
    return;
}

            Zombie::~Zombie(void) // destructor
{
    std::cout << this->ftGetName() <<  RED "\t: AAaaAArgGGghh..." << "\t[Destructor]" RESET << std::endl;
    return;
}

void        Zombie::ftSetName(std::string str)
{
    this->name.assign(str);
    return;
}

std::string Zombie::ftGetName(void) const
{
    return this->name;
}

void        Zombie::ftAnnounce(void) const
{
    std::cout << this->ftGetName() << MAGENTA "\t: BraiiiiiiinnnzzzZ... \t[ftAnnounce]" RESET << std::endl;
    return;
}
