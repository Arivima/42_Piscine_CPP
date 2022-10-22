# include "Animal.class.hpp"

// constructors destructor
            Animal::Animal(void) : _type("Animal") 
{
    if (DEBUG)
    {
        this->_type.assign("Animal"+ std::to_string(std::rand() %100));
        std::cout <<  BOLDYELLOW<< this->_type << RESET YELLOW " appeared !\t\t[Animal Default constructor called]" RESET << *this ;
    }
    return ;
}

            Animal::Animal(const Animal& src)
{
    *this = src;
    if (DEBUG)
        std::cout << BOLDCYAN << this->_type << RESET CYAN " appeared !\t\t[Animal Copy constructor called]" RESET << *this;
    return ;
}

            Animal::~Animal(void)
{
    if (DEBUG)
        std::cout << RED << this->_type << " disapeared...\t\t[Animal Destructor called]" RESET << std::endl;
    return;
}

// getters
std::string Animal::getType(void) const
{
    return this->_type;
}

// setters
void        Animal::setType(std::string type)
{
    this->_type.assign(type);
    return;
}

// operators
Animal &    Animal::operator=(const Animal & src)
{
    if (DEBUG)
    {
        std::cout << "\"" << this->getType();
        std::cout << "\" becomes \"";
        std::cout << src.getType();
        std::cout << "\"\t\t\t\t[Animal Copy assignment operator called]" << std::endl;
    }
    this->setType(src.getType());
    return *this;
}

std::ostream &      operator<<(std::ostream &o, Animal const &object)
{
	o << WHITE << "\t| [" << object.getType() << "] \t{Animal << operator}" << RESET << std::endl;
   
	return o;
}

// functions
void        Animal::makeSound      (void) const
{
	std::cout << MAGENTA << this->getType() << "\t: making an animal sound." RESET << std::endl;
    return;
}

