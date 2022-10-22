# include "Cure.class.hpp"

// Constructors, Destructors
            Cure::Cure(void) : AMateria("cure"), id(std::rand() % 100)
{
    if (DEBUG)
        std::cout << GREEN "\t[Cure]\t\t[Default Constructor]" << *this << std::endl;
    return;
}

            Cure::Cure(const Cure & src): AMateria(src.getType()), id(std::rand() % 100)
{
    *this = src;
    if (DEBUG)
        std::cout << GREEN "\t[Cure]\t\t[Copy Constructor]" << *this << std::endl;
    return;
}

            Cure::~Cure()
{
    if (DEBUG)
        std::cout << RED "\t[Cure]\t\t[Destructor]\t" << *this << std::endl;
    return;
}

// Operators
Cure &       Cure::operator=(const Cure & src)
{
    if (DEBUG)
        std::cout << "\t[Cure]\t\t[Assignment Operator]"<< *this;
    this->ID = src.ID;
    this->id = src.id;    
    if (DEBUG)
        std::cout << "\t becomes " << *this << std::endl;
    return *this;
}

std::ostream &      operator<<(std::ostream &o, Cure const &object)
{
    o << "\t[type:" << object.getType();
    o << "|ID(" YELLOW << object.ID << RESET;
    o << ")|id(" YELLOW << object.id << RESET ")]" << RESET;
	return o;
}

// Member functions
void        Cure::use(ICharacter& target)
{
    if (DEBUG)
        std::cout << *this;
    std::cout << "* heals " << target.getName() << "'s wounds *" << RESET << std::endl;
    return;
}

AMateria*   Cure::clone(void) const
{
    Cure *newCure = new Cure();
    return newCure;
}
