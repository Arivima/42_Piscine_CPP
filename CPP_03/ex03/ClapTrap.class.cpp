# include "ClapTrap.class.hpp"

// constructors destructor
            ClapTrap::ClapTrap(void) 
: _name("Unknown"), _hitPoints(10), _maxHitPoints(10), _energyPoints(10), _attackDamage(0)
{
    if (DEBUG)
        std::cout <<  YELLOW "ClapTrap " RESET BOLDYELLOW<< this->_name << RESET YELLOW " appeared !\t[Default constructor called]" RESET << *this ;
    return ;
}

            ClapTrap::ClapTrap(const ClapTrap& src)
{
    *this = src;
    if (DEBUG)
        std::cout << CYAN "ClapTrap " RESET BOLDCYAN << this->_name << RESET CYAN " appeared !\t[Copy constructor called]" RESET << *this;
    return ;
}

            ClapTrap::ClapTrap(std::string name)
:  _name(name), _hitPoints(10), _maxHitPoints(10), _energyPoints(10), _attackDamage(0)
{
    if (DEBUG)
        std::cout << GREEN "ClapTrap " RESET BOLDGREEN<< this->_name << RESET GREEN " appeared !\t[string constructor called]" RESET << *this;
    return ;
}

            ClapTrap::~ClapTrap(void)
{
    if (DEBUG)
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

int         ClapTrap::getMaxHitPoints(void) const
{
    return this->_maxHitPoints;
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
    if (DEBUG)
    {
        std::cout << this->getName() << " becomes " << src.getName();
        std::cout << "\t\t[Copy assignment operator called]" << std::endl;
    }
    this->setName           (src.getName());
    this->setAttackDamage   (src.getAttackDamage());
    this->setEnergyPoints   (src.getEnergyPoints());
    this->setHitPoints      (src.getHitPoints());
    return *this;
}

std::ostream &      operator<<(std::ostream &o, ClapTrap const &robot)
{
	o << WHITE << "\t| \"" ;
	o << robot.getName() << "\"";
    o << "\t| hit("         << robot.getHitPoints();
    o << "/"                << robot.getMaxHitPoints();
    o << ")\t| energy("     << robot.getEnergyPoints();
    o << ")\t| damage("     << robot.getAttackDamage();
    o << ")\t|" RESET << std::endl;
   
	return o;
}

// public functions
bool        ClapTrap::checkLife(void) const
{
    if (this->getEnergyPoints() > 0 && this->getHitPoints() > 0)
        return 0;
    else
        std::cout << BOLDRED "!" << this->getName() << " is dead !\t\t\t\t\t\t" RESET << *this;
    return 1;
}

void        ClapTrap::attack          (const std::string& target)
{
    if (this->checkLife() == 0)
    {
        std::cout << BOLDWHITE "ClapTrap " << this->getName() << " attacks " << target << ".\t\t\t\t" RESET;
        this->setEnergyPoints(this->getEnergyPoints() - 1);
        std::cout << *this;
    }
    return;
}

void        ClapTrap::takeDamage      (unsigned int amount)
{
    if (this->checkLife() == 0)
    {
        this->getHitPoints() - (int) amount < 0 ? 
            this->setHitPoints(0) : this->setHitPoints(this->getHitPoints() - (int) amount);
        std::cout << CYAN << this->getName() << " takes " << amount << " points of damage!\t\t\t\t" RESET << *this;
    }
    return;
}

void        ClapTrap::beRepaired      (unsigned int amount)
{
    if (this->checkLife() == 0)
    {
        (int) amount + this->getHitPoints() > this->getMaxHitPoints() ? 
            this->setHitPoints(this->getMaxHitPoints()) : this->setHitPoints(this->getHitPoints() + amount);
        this->setEnergyPoints(this->getEnergyPoints() - 1);
        std::cout << GREEN << this->getName() << " repairs itself and gets " << amount << " hit points !\t\t" RESET << *this;
    }
    return;
}

