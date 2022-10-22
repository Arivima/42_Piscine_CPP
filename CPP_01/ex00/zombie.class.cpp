# include "zombie.class.hpp"

            Zombie::Zombie(std::string name) // constructor
{
    this->name.assign(name);
    std::cout << this->ftGetName() <<  "\t: ........ Momma !"<< "\t[Constructor]" << std::endl;
    return;
}

            Zombie::~Zombie(void) // destructor
{
    std::cout << this->ftGetName() <<  "\t: AAaaAArgGGghh..." << "\t[Destructor]" << std::endl;
    return;
}

std::string Zombie::ftGetName(void) const
{
    return this->name;
}

void        Zombie::ftAnnounce(void) const
{
    std::cout << this->ftGetName() << "\t: BraiiiiiiinnnzzzZ... \t[ftAnnounce]" << std::endl;
    return;
}
