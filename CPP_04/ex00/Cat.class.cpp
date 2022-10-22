# include "Cat.class.hpp"

// constructors destructor
            Cat::Cat(void)
{
    this->setType("Cat");
    if (DEBUG)
        std::cout << BOLDYELLOW << this->_type << " appeared !\t\t\t[Cat Default constructor called]" RESET << *this ;
    return ;
}

            Cat::Cat(const Cat& src)
{
    *this = src;
    if (DEBUG)
        std::cout << CYAN       << this->_type << " appeared !\t[Cat Copy constructor called]" RESET << *this;
    return ;
}

            Cat::~Cat(void)
{
    if (DEBUG)
        std::cout << RED        << this->_type << " disapeared...\t\t[Cat Destructor called]" RESET << std::endl;
    return;
}

// operators
Cat &  Cat::operator=(const Cat & src)
{
    if (DEBUG)
    {
        std::cout << "\"" << this->getType() << "\" becomes \"" << src.getType() << "\"";
        std::cout << "\t\t\t[Cat Copy assignment operator called]" << std::endl;
    }
    this->setType(src.getType());
    return *this;
}

std::ostream &      operator<<(std::ostream &o, Cat const &object)
{
	o << WHITE << "\t| [" << object.getType() << "]" RESET << std::endl;
   
	return o;
}

// functions
void        Cat::makeSound      (void) const
{
	std::cout << MAGENTA << this->getType() << "\t: MIAOU." RESET << std::endl;
    return;
}

