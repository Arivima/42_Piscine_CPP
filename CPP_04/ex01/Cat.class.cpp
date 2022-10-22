# include "Cat.class.hpp"

// constructors destructor
            Cat::Cat(void)
{
    this->setType("Cat");
    _Brainp = new Brain();
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
    _delete(_Brainp);
    if (DEBUG)
        std::cout << RED        << this->_type << " disapeared...\t\t[Cat Destructor called]" RESET << std::endl;
    return;
}

// getters
Brain*      Cat::getBrainp(void) const
{
    return this->_Brainp;
}

// setters
void        Cat::setBrainp(Brain* brainp)
{
    *(this->_Brainp) = *brainp;
    return;
}

// operators
Cat &  Cat::operator=(const Cat & src)
{
    if (DEBUG)
    {
        Brain * thisIdeaID = this->getBrainp();
        Brain * srcIdeaID = src.getBrainp();
        
        std::cout << "\"" << this->getType()<< "(" << thisIdeaID->getIdeas(0) << ")" << "\"" ;
        std::cout << " becomes ";
        std::cout << "\"" << src.getType()  << "(" << srcIdeaID->getIdeas(0) << ")"  << "\"";
        std::cout << "\t[Cat = Cat Copy assignment operator called]" << std::endl;
    }
    this->setType(src.getType());
    this->setBrainp(src.getBrainp());
    return *this;
}

Cat &       Cat::operator=(const Animal & src)
{
    if (DEBUG)
    {
        Brain * thisIdeaID = this->getBrainp();

        std::cout << "\"" << this->getType()<< "(" << thisIdeaID->getIdeas(0) << ")" << "\"" ;
        std::cout << " becomes ";
        std::cout << "\"" << src.getType() << "\"";
        std::cout << "\t\t[Cat = Animal Copy assignment operator called]" << std::endl;
    }
    this->setType(src.getType());
    return *this;
}

std::ostream &      operator<<(std::ostream &o, Cat const &object)
{
	Brain * ideaID = object.getBrainp();

    o << WHITE << "\t| [" << object.getType() << "|" YELLOW << ideaID->getIdeas(0) << RESET "] \t{Cat << operator}" << RESET << std::endl;
	return o;
}

// functions
void        Cat::makeSound      (void) const
{
	Brain * ideaID = this->getBrainp();

	std::cout << MAGENTA << this->getType() << "(" << ideaID->getIdeas(0) << ")" << "\t: MIAOU." RESET << std::endl;
    return;
}

