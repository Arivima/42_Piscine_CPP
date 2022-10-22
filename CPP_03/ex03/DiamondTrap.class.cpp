# include "DiamondTrap.class.hpp"

// constructors destructor
            DiamondTrap::DiamondTrap(void) : ClapTrap(), ScavTrap(), FragTrap()
{
    if (DEBUG)
        std::cout <<  BOLDYELLOW "Initializing DiamondTrap values\t\t\t\t" RESET << *this;

    ScavTrap    slap;
    FragTrap    flap;
    
    this->setName       ("Unknown");
    this->setClapName   ("Unknown_clap_name");
    this->_hitPoints    = flap.getHitPoints();
    this->_maxHitPoints = flap.getMaxHitPoints();
    this->_energyPoints = slap.getEnergyPoints();
    this->_attackDamage = flap.getAttackDamage();

    if (DEBUG)
        std::cout <<  MAGENTA "DiamondTrap " RESET BOLDMAGENTA << this->_name << RESET MAGENTA " appeared !\t[Default constructor called]" RESET << *this ;
    return ;
}

            DiamondTrap::DiamondTrap(const DiamondTrap& src)
{
    *this = src;
    if (DEBUG)
        std::cout << CYAN "DiamondTrap " RESET BOLDCYAN << this->_name << RESET CYAN " appeared !\t[Copy constructor called]" RESET << *this;
    return ;
}

            DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"),ScavTrap(name), FragTrap(name)
{
    if (DEBUG)
        std::cout <<  YELLOW "Initializing DiamondTrap values\t\t\t\t" RESET << *this;

    ScavTrap    slap;
    FragTrap    flap;
    
    this->setName           (name);
    this->setClapName       (name + "_clap_name");
    this->_hitPoints        = flap.getHitPoints();
    this->_maxHitPoints     = flap.getMaxHitPoints();
    this->_energyPoints     = slap.getEnergyPoints();
    this->_attackDamage     = flap.getAttackDamage();

    if (DEBUG)
        std::cout << GREEN "DiamondTrap " RESET BOLDGREEN<< this->_name << RESET GREEN " appeared !\t[string constructor called]" RESET << *this;
    return ;
}

            DiamondTrap::~DiamondTrap(void)
{
    if (DEBUG)
        std::cout << RED "DiamondTrap " << this->_name << " disapeared...\t[Destructor called]" RESET << std::endl;
    return;
}

// getters
std::string DiamondTrap::getName(void) const
{
    return this->_name;
}

std::string DiamondTrap::getClapName(void) const
{
    return this->ClapTrap::_name;
}

// setters
void        DiamondTrap::setName(std::string name)
{
    this->_name.assign(name);
    return;
}

void        DiamondTrap::setClapName(std::string name)
{
    this->ClapTrap::_name.assign(name);
    return;
}

// operators
DiamondTrap &  DiamondTrap::operator=(const DiamondTrap & src)
{
    if (DEBUG)
    {
        std::cout << BLUE << this->getName() << " (" << this->getClapName() << ")" << " becomes " << src.getName() << " (" << src.getClapName() << ")";
        std::cout << "\t\t[Copy assignment operator called]" RESET << std::endl;
    }
    this->setName           (src.getName());
    this->setClapName       (src.getClapName());
    this->setAttackDamage   (src.getAttackDamage());
    this->setEnergyPoints   (src.getEnergyPoints());
    this->setHitPoints      (src.getHitPoints());
    return *this;
}

std::ostream &      operator<<(std::ostream &o, DiamondTrap const &robot)
{
	o << WHITE  ;
	o << "\t| \""           << robot.getName() << "\"";
	o << " ("               << robot.getClapName() << ")";
    o << "\t| hit("         << robot.getHitPoints();
    o << "/"                << robot.getMaxHitPoints();
    o << ")\t| energy("     << robot.getEnergyPoints();
    o << ")\t| damage("     << robot.getAttackDamage();
    o << ")\t|" RESET       << std::endl;
   
	return o;
}

	
// functions
void        DiamondTrap::whoAmI(void)
{
    std::string name = this->getName();
    std::transform(name.begin(), name.end(),name.begin(), ::toupper);

    std::string clapname = this->getClapName();
    std::transform(clapname.begin(), clapname.end(),clapname.begin(), ::toupper);

    std::cout << MAGENTA ">> I AM " BOLDMAGENTA << name << RESET MAGENTA " FROM " BOLDMAGENTA << clapname << RESET MAGENTA "." RESET << std::endl;
    return;
}

void        DiamondTrap::attack(const std::string& target)
{
    std::cout << "DiamondTrap attack : ";
    this->ScavTrap::attack(target);
    return;
}