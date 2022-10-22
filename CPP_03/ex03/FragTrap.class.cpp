# include "FragTrap.class.hpp"

// constructors destructor
            FragTrap::FragTrap(void)
{
    this->_name.assign("Unknown");
    this->_hitPoints = 100;
    this->_maxHitPoints = _hitPoints;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    if (DEBUG)
        std::cout <<  YELLOW "FragTrap " RESET BOLDYELLOW<< this->_name << RESET YELLOW " appeared !\t[Default constructor called]" RESET << *this ;
    return ;
}

            FragTrap::FragTrap(const FragTrap& src)
{
    *this = src;
    if (DEBUG)
        std::cout << CYAN "FragTrap " RESET BOLDCYAN << this->_name << RESET CYAN " appeared !\t[Copy constructor called]" RESET << *this;
    return ;
}

            FragTrap::FragTrap(std::string name)
{
    this->_name.assign(name);
    this->_hitPoints = 100;
    this->_maxHitPoints = _hitPoints;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    if (DEBUG)
        std::cout << GREEN "FragTrap " RESET BOLDGREEN<< this->_name << RESET GREEN " appeared !\t[string constructor called]" RESET << *this;
    return ;
}

            FragTrap::~FragTrap(void)
{
    if (DEBUG)
        std::cout << RED "FragTrap " << this->_name << " disapeared...\t[Destructor called]" RESET << std::endl;
    return;
}

// operators
FragTrap &  FragTrap::operator=(const FragTrap & src)
{
    if (DEBUG)
    {
        std::cout << this->getName() << " becomes " << src.getName();
        std::cout << "\t\t[Copy assignment operator called]" << std::endl;
    }
    this->setName(src.getName());
    this->setAttackDamage(src.getAttackDamage());
    this->setEnergyPoints(src.getEnergyPoints());
    this->setHitPoints(src.getHitPoints());
    return *this;
}

std::ostream &      operator<<(std::ostream &o, FragTrap const &robot)
{
	o << WHITE << "\t| \"" ;
	o << robot.getName() << "\"";
    o << "\t| hit("     << robot.getHitPoints();
    o << "/"     << robot.getMaxHitPoints();
    o << ")\t| energy("  << robot.getEnergyPoints();
    o << ")\t| damage("  << robot.getAttackDamage();
    o << ")\t|" RESET << std::endl;
   
	return o;
}

// functions
void        FragTrap::highFivesGuys(void)
{
    if (this->checkLife() == 0)
    {
        std::string agreement;
        std::cout << BOLDYELLOW "\n>> FragTrap " << this->getName() << " would like to high five.\t\t" RESET;
        std::cout << *this;
        std::cout << GREEN ">> Do you accept " << this->getName() << " high five ? [yes] or [no]" RESET << std::endl << ">>";
        std::cin >> agreement;
        if (agreement == "yes")
            std::cout << BOLDYELLOW ">> FragTrap " << this->getName() << " claps your hand, and thanks you for returning this high five.\n" RESET << std::endl;
        else
            std::cout << BOLDMAGENTA ">> Never mind, " << this->getName() << " didn't need a high five anyway.\n" RESET << std::endl;

    }
    return;
}

void        FragTrap::attack(const std::string& target)
{
    if (this->checkLife() == 0)
    {
        this->setEnergyPoints(this->getEnergyPoints() - 1);
        std::cout << BOLDWHITE "FragTrap " << this->getName() << " attacks " << target << ".\t\t\t\t" RESET;
        std::cout << *this;
    }
    return;
}