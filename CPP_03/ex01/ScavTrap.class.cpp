# include "ScavTrap.class.hpp"

// constructors destructor
            ScavTrap::ScavTrap(void)
{
    this->_name.assign("Unknown");
    this->_hitPoints = 100;
    this->_maxHitPoints = _hitPoints;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    this->_gateKeeperMode = 0;
    std::cout <<  YELLOW "ScavTrap " RESET BOLDYELLOW<< this->_name << RESET YELLOW " appeared !\t[Default constructor called]" RESET << std::endl;
    return ;
}

            ScavTrap::ScavTrap(const ScavTrap& src)
{
    *this = src;
    std::cout << CYAN "ScavTrap " RESET BOLDCYAN << this->_name << RESET CYAN " appeared !\t[Copy constructor called]" RESET << std::endl;
    return ;
}

            ScavTrap::ScavTrap(std::string name)
{
    this->_name.assign(name);
    this->_hitPoints = 100;
    this->_maxHitPoints = _hitPoints;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    this->_gateKeeperMode = 0;
    std::cout << GREEN "ScavTrap " RESET BOLDGREEN<< this->_name << RESET GREEN " appeared !\t[string constructor called]" RESET << std::endl;
    return ;
}

            ScavTrap::~ScavTrap(void)
{
    std::cout << RED "ScavTrap " << this->_name << " disapeared...\t[Destructor called]" RESET << std::endl;
    return;
}

// getters
bool         ScavTrap::getMode(void) const
{
    return this->_gateKeeperMode;
}

// setters
void        ScavTrap::setMode(bool mode)
{
    this->_gateKeeperMode = mode;
    return;
}

// operators
ScavTrap &  ScavTrap::operator=(const ScavTrap & src)
{
    std::cout << this->getName() << " becomes " << src.getName();
    std::cout << "\t\t[Copy assignment operator called]" << std::endl;
    this->setName(src.getName());
    this->setAttackDamage(src.getAttackDamage());
    this->setEnergyPoints(src.getEnergyPoints());
    this->setHitPoints(src.getHitPoints());
    this->setMode(src.getMode());
    return *this;
}

std::ostream &      operator<<(std::ostream &o, ScavTrap const &robot)
{
	// o << WHITE << "\t| ScavTrap | \"" ;
	o << WHITE << "\t| \"" ;
	o << robot.getName() << "\"";
    o << "\t| hit("     << robot.getHitPoints();
    o << "/"     << robot.getMaxHitPoints();
    o << ")\t| energy("  << robot.getEnergyPoints();
    o << ")\t| damage("  << robot.getAttackDamage();
    o << ")\t| mode("  << robot.getMode();
    o << ")\t|" RESET << std::endl;
   
	return o;
}

// functions
void        ScavTrap::guardGate(void)
{
    if (this->checkLife() == 0)
    {
        this->setMode(1);
        std::cout << BOLDWHITE "ScavTrap " << this->getName() << " is now in gatekeeper mode " << ".\t\t" RESET;
        std::cout << *this;
    }
    return;
}

void        ScavTrap::attack(const std::string& target)
{
    if (this->checkLife() == 0)
    {
        this->setMode(0);
        this->setEnergyPoints(this->getEnergyPoints() - 1);
        std::cout << BOLDWHITE "ScavTrap " << this->getName() << " attacks " << target << ".\t\t\t\t" RESET;
        std::cout << *this;
    }
    return;
}