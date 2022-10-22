# include "WrongAnimal.class.hpp"

// constructors destructor
            WrongAnimal::WrongAnimal(void) : _type("WrongAnimal")
{
    if (DEBUG)
        std::cout <<  BOLDYELLOW<< this->_type << RESET YELLOW " appeared !\t\t[WrongAnimal Default constructor called]" RESET << *this ;
    return ;
}

            WrongAnimal::WrongAnimal(const WrongAnimal& src)
{
    *this = src;
    if (DEBUG)
        std::cout << BOLDCYAN << this->_type << RESET CYAN " appeared !\t\t[WrongAnimal Copy constructor called]" RESET << *this;
    return ;
}

            WrongAnimal::~WrongAnimal(void)
{
    if (DEBUG)
        std::cout << RED << this->_type << " disapeared...\t\t[WrongAnimal Destructor called]" RESET << std::endl;
    return;
}

// getters
std::string WrongAnimal::getType(void) const
{
    return this->_type;
}

// setters
void        WrongAnimal::setType(std::string type)
{
    this->_type.assign(type);
    return;
}

// operators
WrongAnimal &    WrongAnimal::operator=(const WrongAnimal & src)
{
    if (DEBUG)
    {
        std::cout << "\"" << this->getType() << "\" becomes \"" << src.getType() << "\"";
        std::cout << "\t\t\t\t[WrongAnimal Copy assignment operator called]" << std::endl;
    }
    this->setType(src.getType());
    return *this;
}

std::ostream &      operator<<(std::ostream &o, WrongAnimal const &object)
{
	o << WHITE << "\t| [" << object.getType() << "]" RESET << std::endl;
   
	return o;
}

// functions
void        WrongAnimal::makeSound      (void) const
{
	std::cout << MAGENTA << this->getType() << "\t: making an WrongAnimal sound." RESET << std::endl;
    return;
}

