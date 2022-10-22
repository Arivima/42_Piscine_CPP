# include "weapon.class.hpp"

// constructor
            Weapon::Weapon(std::string typeStr) : type(typeStr)
{
    std::cout << GREEN "A new weapon appeared: \t["<< this->ftGetType() << "]\t\t[Constructor]" RESET << std::endl;
    return;
}
            Weapon::Weapon(void)
{
    return;
}

// destructor
            Weapon::~Weapon(void) 
{
    std::cout <<  RED "A weapon disapeared: \t["<< this->ftGetType() << "]\t\t[Destructor]" RESET  <<  std::endl;
    return;
}

void        Weapon::ftSetType(std::string newtype)
{
    std::cout <<  MAGENTA "Changed weapon: \t[" BOLDMAGENTA << this->ftGetType() ;
    this->type.assign(newtype);
    std::cout << RESET MAGENTA "] to [" RESET BOLDMAGENTA << this->ftGetType() << MAGENTA "]." RESET  <<  std::endl;
    return;
}

std::string const &Weapon::ftGetType(void) const 
{
    std::string const &refType = this->type;
    return refType;
}

