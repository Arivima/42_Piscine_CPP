#include "RobotomyRequestForm.hpp"

// Constructors
RobotomyRequestForm::RobotomyRequestForm() 
: AForm("RobotForm", 72, 45), _target("?")
{
	if (DEBUG)
		std::cout << GREEN "[Default Constructor]\t[Robot]\t" RESET << *this << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) 
: AForm(copy.getName(), copy.getGradeToSign(), copy.getGradeToExec()), _target(copy.getTarget())
{
	if (DEBUG)
		std::cout << GREEN "[Copy Constructor]\t[Robot]\t" RESET << *this << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) 
: AForm("RobotForm", 72, 45), _target(target)
{
	if (DEBUG)
		std::cout << GREEN "[String Constructor]\t[Robot]\t" RESET << *this << RESET << std::endl;
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm()
{
	if (DEBUG)
		std::cout << RED "[Destructor]\t\t[Robot]\t" RESET << *this << RESET << std::endl;
}

// Operators
RobotomyRequestForm &	RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
    if (DEBUG)
        std::cout << CYAN "[Assignment Operator]\t[Robot]\t" RESET << *this;
	// AForm
	this->setGradeToSign(src.getGradeToSign());
	this->setGradeToExec(src.getGradeToExec());
	this->setSigned(src.getSigned());
	// Robot
	this->setTarget(src.getTarget());

    if (DEBUG)
		std::cout << " becomes " << *this << std::endl;
	return *this;
}

RobotomyRequestForm &	RobotomyRequestForm::operator=(const AForm &src)
{
    if (DEBUG)
        std::cout << CYAN "[Assignment Operator]\t[Robot]\t" RESET << *this;
	// AForm
	this->setGradeToSign(src.getGradeToSign());
	this->setGradeToExec(src.getGradeToExec());
	this->setSigned(src.getSigned());
	 
    if (DEBUG)
		std::cout << " becomes " << *this << std::endl;
	return *this;
}

// Getters
std::string		RobotomyRequestForm::getTarget(void) const
{
	return _target;
}

// Setters
void			RobotomyRequestForm::setTarget(std::string target)
{
	this->_target.assign(target);
	return;
}
// Functions
void			RobotomyRequestForm::Robotomize(Bureaucrat const & executor) const
{
	std::cout << executor << " makes drilling noise..." << std::endl;
	try
	{
		if (std::rand() % 2 == 0)
		{
			std::cout << GREEN ">> Robotomy was a success. " << this->getTarget() << " has been robotomized." RESET << std::endl;
		}
		else
		{
			throw ">> Robotomy attempt has failed";
		}
	}
	catch(char const* err)
	{
		std::cerr << RED << err << RESET << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	return;
}

void			RobotomyRequestForm::executeDerived(Bureaucrat const & executor) const
{
	Robotomize(executor);
}

// Stream operators
std::ostream &	operator<<(std::ostream &stream, const RobotomyRequestForm &object)
{
	stream << "["			MAGENTA	<< object.getName()			<< RESET;
	stream << "\t|signed:"	YELLOW 	<< object.getSigned()		<< RESET;
	stream << "\t|G2Sign:"	CYAN  	<< object.getGradeToSign()	<< RESET;
	stream << "\t|G2Exec:"	BLUE 	<< object.getGradeToExec()	<< RESET;
	stream << "\t|Target:"	GREEN 	<< object.getTarget()		<< RESET "]";
	return stream;
}

