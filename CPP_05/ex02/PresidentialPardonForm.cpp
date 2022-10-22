#include "PresidentialPardonForm.hpp"

// Constructors
PresidentialPardonForm::PresidentialPardonForm() 
: AForm("Presid.Form", 25, 5), _target("?")
{
	if (DEBUG)
		std::cout << GREEN "[Default Constructor]\t[Presid.]\t" RESET << *this << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) 
: AForm(copy.getName(), copy.getGradeToSign(), copy.getGradeToExec()), _target(copy.getTarget())
{
	if (DEBUG)
		std::cout << GREEN "[Copy Constructor]\t[Presid.]\t" RESET << *this << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) 
: AForm("Presid.Form", 25, 5), _target(target)
{
	if (DEBUG)
		std::cout << GREEN "[String Constructor]\t[Presid.]\t" RESET << *this << RESET << std::endl;
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm()
{
	if (DEBUG)
		std::cout << RED "[Destructor]\t\t[Presid.]\t" RESET << *this << RESET << std::endl;
}

// Operators
PresidentialPardonForm &	PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
    if (DEBUG)
        std::cout << CYAN "[Assignment Operator]\t[Presid.]\t" RESET << *this;
	// AForm
	this->setGradeToSign(src.getGradeToSign());
	this->setGradeToExec(src.getGradeToExec());
	this->setSigned(src.getSigned());
	// Presid.
	this->setTarget(src.getTarget());

    if (DEBUG)
		std::cout << " becomes " << *this << std::endl;
	return *this;
}

PresidentialPardonForm &	PresidentialPardonForm::operator=(const AForm &src)
{
    if (DEBUG)
        std::cout << CYAN "[Assignment Operator]\t[Presid.]\t" RESET << *this;
	// AForm
	this->setGradeToSign(src.getGradeToSign());
	this->setGradeToExec(src.getGradeToExec());
	this->setSigned(src.getSigned());
	 
    if (DEBUG)
		std::cout << " becomes " << *this << std::endl;
	return *this;
}

// Getters
std::string		PresidentialPardonForm::getTarget(void) const
{
	return _target;
}

// Setters
void			PresidentialPardonForm::setTarget(std::string target)
{
	this->_target.assign(target);
	return;
}
// Functions
void			PresidentialPardonForm::pardon(Bureaucrat const &) const
{
	std::cout << BLUE << this->getTarget() << " was pardoned by Zaphod Beeblebrox" RESET << std::endl;
	return;
}

void			PresidentialPardonForm::executeDerived(Bureaucrat const & executor) const
{
	pardon(executor);
}

// Stream operators
std::ostream &	operator<<(std::ostream &stream, const PresidentialPardonForm &object)
{
	stream << "["			MAGENTA	<< object.getName()			<< RESET;
	stream << "\t|signed:"	YELLOW 	<< object.getSigned()		<< RESET;
	stream << "\t|G2Sign:"	CYAN  	<< object.getGradeToSign()	<< RESET;
	stream << "\t|G2Exec:"	BLUE 	<< object.getGradeToExec()	<< RESET;
	stream << "\t|Target:"	GREEN 	<< object.getTarget()		<< RESET "]";
	return stream;
}

