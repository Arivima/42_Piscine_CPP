# include "Brain.class.hpp"

// constructors destructor
            Brain::Brain(void)
{
    if (DEBUG)
    {
        std::cout <<  BOLDYELLOW<< "Brain" << RESET YELLOW " appeared !\t\t[Brain Default constructor called]" RESET << std::endl;
        for (int i = 0; i < IDEAS_NB; i++)
            this->setIdeas(std::to_string(i), i);
        this->setIdeas(std::to_string(std::rand() % 100), 0);
    }
    return ;
}

            Brain::Brain(const Brain& src)
{
    *this = src;
    if (DEBUG)
        std::cout << "[Brain Copy constructor called]" RESET << std::endl;
    return ;
}

            Brain::~Brain(void)
{
    if (DEBUG)
        std::cout << RED "Brain disappeared...\t\t[Brain Destructor called]" RESET << std::endl;
    return;
}

// getters
std::string Brain::getIdeas(int i) const
{
    return this->_ideas[i];
}

// setters
void        Brain::setIdeas(std::string ideas, int i)
{
    this->_ideas[i].assign(ideas);
    return;
}

// operators
Brain &     Brain::operator=(const Brain & src)
{
    if (DEBUG)
        std::cout << "\t\t\t\t[Brain Copy assignment operator called]" << std::endl;
    for (int i = 0; i < IDEAS_NB; i++)
        setIdeas(src.getIdeas(i), i);
    return *this;
}

std::ostream &      operator<<(std::ostream &o, Brain const &object)
{
	o << WHITE << "\t| Brain [";
    for (int i = 0; i < IDEAS_NB; i++)
        o << object.getIdeas(i) << "|";
    o << "] \t{Brain << operator}" << RESET << std::endl;
   
	return o;
}