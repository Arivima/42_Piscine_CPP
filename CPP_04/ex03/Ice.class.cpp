# include "Ice.class.hpp"

// Constructors, Destructors
            Ice::Ice(void) : AMateria("ice"), id(std::rand() % 100)
{
    if (DEBUG)
        std::cout << GREEN "\t[Ice]\t\t[Default Constructor]" << *this << std::endl;
    return;
}

            Ice::Ice(const Ice & src) : AMateria(src.getType()), id(std::rand() % 100)
{
    *this = src;
    if (DEBUG)
        std::cout << GREEN "\t[Ice]\t\t[Copy Constructor]" << *this << std::endl;
    return;
}

            Ice::~Ice()
{
    if (DEBUG)
        std::cout << RED "\t[Ice]\t\t[Destructor]\t" << *this << std::endl;
    return;
}

// Operators
Ice &       Ice::operator=(const Ice & src)
{
    if (DEBUG)
        std::cout << "\t[Ice]\t\t[Assignment Operator]"<< *this;
    this->ID = src.ID;
    this->id = src.id;    
    if (DEBUG)
        std::cout << "\t becomes " << *this << std::endl;
    return *this;
}

std::ostream &      operator<<(std::ostream &o, Ice const &object)
{
    o << "\t[type:" << object.getType();
    o << "|ID(" YELLOW << object.ID << RESET;
    o << ")|id(" YELLOW << object.id << RESET ")]" << RESET;
	return o;
}

// Member functions
void        Ice::use(ICharacter& target)
{
    if (DEBUG)
        std::cout << *this;
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << RESET << std::endl;
    return;
}

AMateria*   Ice::clone(void) const
{
    Ice *newIce = new Ice();
    return newIce;
}
