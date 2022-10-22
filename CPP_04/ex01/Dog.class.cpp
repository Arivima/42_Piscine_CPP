# include "Dog.class.hpp"

// constructors destructor
            Dog::Dog(void)
{
    this->setType("Dog");
    _Brainp = new Brain();
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
    _delete(_Brainp);
    if (DEBUG)
        std::cout << RED        << this->_type << " disapeared...\t\t[Dog Destructor called]" RESET << std::endl;
    return;
}

// getters
Brain*      Dog::getBrainp(void) const
{
    return this->_Brainp;
}

// setters
void        Dog::setBrainp(Brain* brainp)
{
    *(this->_Brainp) = *brainp;
    return;
}

// operators
Dog &       Dog::operator=(const Dog & src)
{
    if (DEBUG)
    {
        Brain * thisIdeaID = this->getBrainp();
        Brain * srcIdeaID = src.getBrainp();
        
        std::cout << "\"" << this->getType()<< "(" << thisIdeaID->getIdeas(0) << ")" << "\"" ;
        std::cout << " becomes ";
        std::cout << "\"" << src.getType()  << "(" << srcIdeaID->getIdeas(0) << ")"  << "\"";
        std::cout << "\t[Dog = Dog Copy assignment operator called]" << std::endl;
    }
    this->setType(src.getType());
    this->setBrainp(src.getBrainp());
    return *this;
}

Dog &       Dog::operator=(const Animal & src)
{
    if (DEBUG)
    {
        Brain * thisIdeaID = this->getBrainp();

        std::cout << "\"" << this->getType()<< "(" << thisIdeaID->getIdeas(0) << ")" << "\"" ;
        std::cout << " becomes ";
        std::cout << "\"" << src.getType() << "\"";
        std::cout << "\t\t[Dog = Animal Copy assignment operator called]" << std::endl;
    }
    this->setType(src.getType());
    return *this;
}

std::ostream &      operator<<(std::ostream &o, Dog const &object)
{
	Brain * ideaID = object.getBrainp();

    o << WHITE << "\t| [" << object.getType() << "|" YELLOW << ideaID->getIdeas(0) << RESET "] \t{Dog << operator}" << RESET << std::endl;
	return o;
}

// functions
void        Dog::makeSound      (void) const
{
	Brain * ideaID = this->getBrainp();

	std::cout << MAGENTA << this->getType() << "(" << ideaID->getIdeas(0) << ")" << "\t: WOUAF." RESET << std::endl;
    return;
}

