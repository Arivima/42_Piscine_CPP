# include "humanA.class.hpp"

// constructor
            HumanA::HumanA(std::string nameStr, Weapon &type) : name(nameStr), weapon_type(type)
{
    std::cout << GREEN ">[" << this->name << "] appeared with a \t[" << this->weapon_type.ftGetType() << "].\t\t[HumanA Constructor]" RESET << std::endl;
    return;
}

// destructor
            HumanA::~HumanA(void) 
{
    std::cout <<  RED ">[" << this->name << "] disappeared.\t\t\t\t\t[HumanA Destructor]" RESET  <<  std::endl;
    return;
}

void        HumanA::ftAttack(void) const
{
    std::cout << YELLOW "!![" << this->name << "] attacks with their [" << this->weapon_type.ftGetType() << "]." RESET << std::endl;
    return;
}
