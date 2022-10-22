# include "AMateria.class.hpp"

// Constructors, Destructors
                    AMateria::AMateria(void) : _type("Default"), ID(std::rand() % 100)
{
    if (DEBUG)
        std::cout << GREEN "\t[AMateria]\t[Default Constructor]" << *this << std::endl;
    return;
}

                    AMateria::AMateria(std::string const & type) : _type(type), ID(std::rand() % 100)
{
    if (DEBUG)
        std::cout << GREEN "\t[AMateria]\t[String Constructor]"<< *this << std::endl;
    return;
}

                    AMateria::AMateria(const AMateria & src) : _type(src.getType())
{
    *this = src;
    if (DEBUG)
        std::cout << GREEN "\t[AMateria]\t[Copy Constructor]"<< *this << std::endl;
    return;
}

                    AMateria::~AMateria()
{
    if (DEBUG)
        std::cout << RED "\t[AMateria]\t[Destructor]\t" << *this << std::endl;
    return;
}

// Operators
AMateria &          AMateria::operator=   (const AMateria & src)
{
    if (DEBUG)
        std::cout << "\t[AMateria]\t\t[Assignment Operator]" << *this;
    this->ID = src.ID;
    if (DEBUG)
        std::cout << "\t becomes " << *this << std::endl;
    return *this;
}


std::ostream &      operator<<(std::ostream &o, AMateria const &object)
{
    o << "\t[type: " << object.getType() << " | ID: " YELLOW << object.ID << RESET "]" << RESET;
	return o;
}

// Getters, Setters
std::string const & AMateria::getType     (void) const
{
    return this->_type;
}

void                AMateria::setType     (std::string const type)
{
    this->_type.assign(type);
    return;
}

// Member functions
void        AMateria::use         (ICharacter& target)
{
    std::cout << *this << "* AMateria is a Abstract class and does nothing at " << target.getName() << " *" RESET << std::endl;
    return;
}
