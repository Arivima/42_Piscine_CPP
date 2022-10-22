# include "humanB.class.hpp"

// constructor
            HumanB::HumanB(std::string nameStr) : name(nameStr), weapon_type()
{
    std::cout << GREEN ">[" << this->name << "] appeared.\t\t\t\t\t[HumanB Constructor]" RESET << std::endl;
    return;
}

// destructor
            HumanB::~HumanB(void) 
{
    std::cout <<  RED ">[" << this->name << "] disappeared.\t\t\t\t\t[HumanB Destructor]" RESET  <<  std::endl;
    return;
}

void        HumanB::ftAttack(void) const
{
    std::cout << YELLOW "!![" << this->name << "] attacks with their [" << this->weapon_type->ftGetType() << "]." RESET << std::endl;
    return;
}

void        HumanB::ftSetWeapon(Weapon &newWeapon)
{
    this->weapon_type = &newWeapon;
    std::cout << YELLOW ">[" << this->name << "] sets new weapon [" << this->weapon_type->ftGetType() << "]." RESET << std::endl;
    return;
}