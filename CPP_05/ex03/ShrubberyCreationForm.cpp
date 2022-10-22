#include "ShrubberyCreationForm.hpp"

// Constructors
ShrubberyCreationForm::ShrubberyCreationForm() 
: AForm("ShrubForm", 145, 137), _target("?")
{
	if (DEBUG)
		std::cout << GREEN "[Default Constructor]\t[Shrub]\t" RESET << *this << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) 
: AForm(copy.getName(), copy.getGradeToSign(), copy.getGradeToExec()), _target(copy.getTarget())
{
	if (DEBUG)
		std::cout << GREEN "[Copy Constructor]\t[Shrub]\t" RESET << *this << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) 
: AForm("ShrubForm", 145, 137), _target(target)
{
	if (DEBUG)
		std::cout << GREEN "[String Constructor]\t[Shrub]\t" RESET << *this << RESET << std::endl;
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	if (DEBUG)
		std::cout << RED "[Destructor]\t\t[Shrub]\t" RESET << *this << RESET << std::endl;
}

// Operators
ShrubberyCreationForm &	ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
    if (DEBUG)
        std::cout << CYAN "[Assignment Operator]\t[Shrub]\t" RESET << *this;
	// AForm
	this->setGradeToSign(src.getGradeToSign());
	this->setGradeToExec(src.getGradeToExec());
	this->setSigned(src.getSigned());
	// Shrub
	this->setTarget(src.getTarget());

    if (DEBUG)
		std::cout << " becomes " << *this << std::endl;
	return *this;
}

ShrubberyCreationForm &	ShrubberyCreationForm::operator=(const AForm &src)
{
    if (DEBUG)
        std::cout << CYAN "[Assignment Operator]\t[Shrub]\t" RESET << *this;
	// AForm
	this->setGradeToSign(src.getGradeToSign());
	this->setGradeToExec(src.getGradeToExec());
	this->setSigned(src.getSigned());
	 
    if (DEBUG)
		std::cout << " becomes " << *this << std::endl;
	return *this;
}

// Getters
std::string		ShrubberyCreationForm::getTarget(void) const
{
	return _target;
}

// Setters
void			ShrubberyCreationForm::setTarget(std::string target)
{
	this->_target.assign(target);
	return;
}
// Functions
void			ShrubberyCreationForm::createShrub(void) const
{
	std::ofstream		fileOut;
	std::string const	fileName = (this->getTarget() + "_shrubbery");

	fileOut.exceptions ( std::ofstream::failbit | std::ofstream::badbit );
	try
	{
		fileOut.open (fileName, std::ofstream::out | std::ofstream::trunc);
		for (int i = 0; i < 3; i++)
			printShrub(fileOut);
		fileOut.close();
	}
	catch (const std::ofstream::failure& e)
	{
		std::cerr << RED "Exception dealing with output file: " << e.what() << RESET << std::endl;
	}
	return;
}

void			ShrubberyCreationForm::printShrub(std::ofstream &stream) const
{
	stream << "#----------------------------------------" << std::endl;
	stream << "#			,@@@@@@@," << std::endl;
	stream << "#	,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
	stream << "#,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
	stream << "#,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
	stream << "#%&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
	stream << "#%&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
	stream << "#`&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
	stream << "#	|o|        | |         | |" << std::endl;
	stream << "#	|.|        | |         | |" << std::endl;
	stream << "#\\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_" << std::endl;
	stream << "#----------------------------------------" << std::endl;
	return;
}

void			ShrubberyCreationForm::executeDerived(Bureaucrat const &) const
{
	createShrub();
}

// Stream operators
std::ostream &	operator<<(std::ostream &stream, const ShrubberyCreationForm &object)
{
	stream << "["			MAGENTA	<< object.getName()			<< RESET;
	stream << "\t|signed:"	YELLOW 	<< object.getSigned()		<< RESET;
	stream << "\t|G2Sign:"	CYAN  	<< object.getGradeToSign()	<< RESET;
	stream << "\t|G2Exec:"	BLUE 	<< object.getGradeToExec()	<< RESET;
	stream << "\t|Target:"	GREEN 	<< object.getTarget()		<< RESET "]";
	return stream;
}

