# include "Dog.class.hpp"

// constructors destructor
            Dog::Dog(void)
{
    this->setType("Dog");
    if (DEBUG)
        std::cout << BOLDYELLOW << this->_type << " appeared !\t\t\t[Dog Default constructor called]" RESET << *this ;
    return ;
}

            Dog::Dog(const Dog& src)
{
    *this = src;
    if (DEBUG)
        std::cout << CYAN       << this->_type << " appeared !\t[Dog Copy constructor called]" RESET << *this;
    return ;
}

            Dog::~Dog(void)
{
    if (DEBUG)
        std::cout << RED        << this->_type << " disapeared...\t\t[Dog Destructor called]" RESET << std::endl;
    return;
}

// operators
Dog &  Dog::operator=(const Dog & src)
{
    if (DEBUG)
    {
        std::cout << "\"" << this->getType() << "\" becomes \"" << src.getType() << "\"";
        std::cout << "\t\t\t[Dog Copy assignment operator called]" << std::endl;
    }
    this->setType(src.getType());
    return *this;
}

std::ostream &      operator<<(std::ostream &o, Dog const &object)
{
	o << WHITE << "\t| [" << object.getType() << "]" RESET << std::endl;
   
	return o;
}

// functions
void        Dog::makeSound      (void) const
{
	std::cout << MAGENTA << this->getType() << "\t: WOUAF." RESET << std::endl;
    return;
}

