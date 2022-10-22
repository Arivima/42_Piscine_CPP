# include "ClapTrap.class.hpp"

// constructors destructor
            ClapTrap::ClapTrap(void) 
: _name("ClapClap"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout <<  YELLOW "ClapTrap " RESET BOLDYELLOW<< this->_name << RESET YELLOW " appeared !\t[Default constructor called]" RESET << std::endl;
    return ;
}

            ClapTrap::ClapTrap(const ClapTrap& src)
{
    *this = src;
    std::cout << CYAN "ClapTrap " RESET BOLDCYAN << this->_name << RESET CYAN " appeared !\t[Copy constructor called]" RESET << std::endl;
    return ;
}

            ClapTrap::ClapTrap(std::string name)
: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << GREEN "ClapTrap " RESET BOLDGREEN<< this->_name << RESET GREEN " appeared !\t[string constructor called]" RESET << std::endl;
    return ;
}

            ClapTrap::~ClapTrap(void)
{
    std::cout << RED "ClapTrap " << this->_name << " disapeared...\t[Destructor called]" RESET << std::endl;
    return;
}

// getters
std::string ClapTrap::getName(void) const
{
    return this->_name;
}

int         ClapTrap::getAttackDamage(void) const
{
    return this->_attackDamage;
}

int         ClapTrap::getEnergyPoints(void) const
{
    return this->_energyPoints;
}

int         ClapTrap::getHitPoints(void) const
{
    return this->_hitPoints;
}

// setters
void        ClapTrap::setName(std::string name)
{
    this->_name = name;
    return;
}

void        ClapTrap::setAttackDamage(int n)
{
    this->_attackDamage = n;
    return;
}

void        ClapTrap::setEnergyPoints(int n)
{
    this->_energyPoints = n;
    return;
}

void        ClapTrap::setHitPoints(int n)
{
    this->_hitPoints = n;
    return;
}

// operators
ClapTrap &  ClapTrap::operator=(const ClapTrap & src)
{
    std::cout << this->getName() << " becomes " << src.getName() << "\t\t[Copy assignment operator called]" << std::endl;
    this->_name = src.getName();
    this->_attackDamage = src.getAttackDamage();
    this->_energyPoints = src.getEnergyPoints();
    this->_hitPoints = src.getHitPoints();
    return *this;
}

std::ostream &      operator<<(std::ostream &o, ClapTrap const &clapclap)
{
	o << YELLOW;
	o << "\t| ClapTrap "        << clapclap.getName();
    o << "\t| hit points: "     << clapclap.getHitPoints();
    o << "\t| energy points: "  << clapclap.getEnergyPoints();
    o << "\t| attack damage: "  << clapclap.getAttackDamage();
    o << "." RESET << std::endl;
   
	return o;
}

// public functions
void        ClapTrap::attack          (const std::string& target)
{
    if (this->getEnergyPoints() > 0 && this->getHitPoints() > 0)
    {
        std::cout << BOLDWHITE "ClapTrap " << this->getName() << " attacks " << target << ".\t\t\t\t" RESET;
        this->setEnergyPoints(this->getEnergyPoints() - 1);
        this->setAttackDamage(this->getAttackDamage() + 1);
        std::cout << *this;
    }
    else
        std::cout << BOLDRED "! ClapTrap " << this->getName() << " cannot do anything !\t\t" RESET << *this;
    return;
}

void        ClapTrap::takeDamage      (unsigned int amount)
{
    if (this->getEnergyPoints() > 0 && this->getHitPoints() > 0)
    {
        (int) amount <= this->getHitPoints() ? this->setHitPoints(amount) : this->setHitPoints(0);
        std::cout << CYAN "ClapTrap " << this->getName() << " takes " << amount << " points of damage!\t\t\t" RESET << *this;
    }
    else
        std::cout << BOLDRED "! ClapTrap " << this->getName() << " is already dead.\t\t" RESET << *this;
    return;
}

void        ClapTrap::beRepaired      (unsigned int amount)
{
    if (this->getEnergyPoints() > 0 && this->getHitPoints() > 0)
    {
        amount + this->getHitPoints() > 10 ? this->setHitPoints(10) : this->setHitPoints(this->getHitPoints() + amount);
        this->setEnergyPoints(this->getEnergyPoints() - 1);
        std::cout << GREEN "ClapTrap " << this->getName() << " repairs itself and gets " << amount << " hit points !\t" RESET << *this;
    }
    else
        std::cout << BOLDRED "! ClapTrap " << this->getName() << " cannot do anything !\t\t\t" RESET << *this;
    return;
}

