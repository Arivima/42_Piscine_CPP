# include "WrongCat.class.hpp"

// constructors destructor
            WrongCat::WrongCat(void)
{
    this->setType("WrongCat");
    if (DEBUG)
        std::cout << BOLDYELLOW << this->_type << " appeared !\t\t\t[WrongCat Default constructor called]" RESET << *this ;
    return ;
}

            WrongCat::WrongCat(const WrongCat& src)
{
    *this = src;
    if (DEBUG)
        std::cout << CYAN       << this->_type << " appeared !\t[WrongCat Copy constructor called]" RESET << *this;
    return ;
}

            WrongCat::~WrongCat(void)
{
    if (DEBUG)
        std::cout << RED        << this->_type << " disapeared...\t\t[WrongCat Destructor called]" RESET << std::endl;
    return;
}

// operators
WrongCat &  WrongCat::operator=(const WrongCat & src)
{
    if (DEBUG)
    {
        std::cout << "\"" << this->getType() << "\" becomes \"" << src.getType() << "\"";
        std::cout << "\t\t\t[WrongCat Copy assignment operator called]" << std::endl;
    }
    this->setType(src.getType());
    return *this;
}

std::ostream &      operator<<(std::ostream &o, WrongCat const &object)
{
	o << WHITE << "\t| [" << object.getType() << "]" RESET << std::endl;
   
	return o;
}

// functions
void        WrongCat::makeSound      (void) const
{
	std::cout << MAGENTA << this->getType() << "\t: WRONGMIAOU." RESET << std::endl;
    return;
}

