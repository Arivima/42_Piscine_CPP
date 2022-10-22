#include "Bureaucrat.hpp"

// Constructors
				Bureaucrat::Bureaucrat() : _name("Unknown"), _grade(150)
{
	if (DEBUG)
		std::cout << GREEN "[Default Constructor]\t[Bureaucrat]\t[" << this->_name << "]\t[" << this->_grade << "]" RESET << std::endl;
}

				Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy.getName()), _grade(copy.getGrade())
{
	if (DEBUG)
		std::cout << GREEN "[Copy Constructor]\t[Bureaucrat]\t[" << this->_name << "]\t[" << this->_grade << "]" RESET << std::endl;
}

				Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	this->setGrade(grade);
	if (DEBUG)
		std::cout << GREEN "[Fields Constructor]\t[Bureaucrat]\t[" << this->_name << "]\t[" << this->_grade << "]" RESET << std::endl;
}

// Destructor
				Bureaucrat::~Bureaucrat()
{
	if (DEBUG)
		std::cout << RED "[Destructor]\t\t[Bureaucrat]" RESET << std::endl;
}

// Operators
Bureaucrat &	Bureaucrat::operator=(const Bureaucrat &src)
{
    if (DEBUG)
        std::cout << CYAN "[Assignment Operator]\t[Bureaucrat]\t" RESET << *this;

	this->setGrade(src.getGrade());

    if (DEBUG)
		std::cout << " becomes " << *this << std::endl;
	return *this;
}

// Getters 
std::string		Bureaucrat::getName() const
{
	return _name;
}
int				Bureaucrat::getGrade() const
{
	return _grade;
}

// Setters
void			Bureaucrat::setGrade(int grade)
{
	try
	{
		if (grade > 150)
		{
			_grade = 150;
			throw Bureaucrat::GradeTooLow();
		}
		else if (grade < 1)
		{
			_grade = 1;
			throw Bureaucrat::GradeTooHigh();
		}
		else
			this->_grade = grade;
	}
	catch (Bureaucrat::GradeTooLow & e)
	{
		std::cerr << BOLDRED ">> Bureaucrat: " << e.what() << ": Setting grade to 150" << RESET << std::endl;
	}
	catch (Bureaucrat::GradeTooHigh & e)
	{
		std::cerr << BOLDRED ">> Bureaucrat: " << e.what() << ": Setting grade to 1" << RESET << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << std::endl << BOLDRED ">>" << e.what() << RESET << std::endl;
	}
	return;
}

// Stream operators
std::ostream &	operator<<(std::ostream &stream, const Bureaucrat &object)
{
	stream << "[" MAGENTA << object.getName() << RESET "|" YELLOW << object.getGrade() << RESET "]";
	return stream;
}

// Functions
void			Bureaucrat::incrGrade(void)
{
    if (DEBUG)
        std::cout << CYAN "[incrGrade]\t\t[Bureaucrat]\t" RESET<< *this;
	this->setGrade(this->getGrade() - 1);
    if (DEBUG)
		std::cout << " becomes "<< *this << std::endl;
	return;
}

void			Bureaucrat::decrGrade(void)
{
    if (DEBUG)
        std::cout << CYAN "[decrGrade]\t\t[Bureaucrat]\t" RESET<< *this;
	this->setGrade(this->getGrade() + 1);
    if (DEBUG)
        std::cout << " becomes "<< *this << std::endl;
	return;
}

void			Bureaucrat::signForm(AForm & form)
{
	form.beSigned(*this);
	return;
}

void			Bureaucrat::executeForm(AForm const &form)
{
	form.execute(*this);
	return;
}