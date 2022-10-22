#include "Intern.hpp"

// Constructors
				Intern::Intern()
{
	if (DEBUG)
		std::cout << GREEN "[Default Constructor]\t[Intern]" RESET << std::endl;
}

				Intern::Intern(const Intern &copy)
{
	*this = copy;
	if (DEBUG)
		std::cout << GREEN "[Copy Constructor]\t[Intern]" RESET << std::endl;
}

// Destructor
				Intern::~Intern()
{
	if (DEBUG)
		std::cout << RED "[Destructor]\t\t[Intern]" RESET << std::endl;
}

// Operators
Intern &		Intern::operator=(const Intern &)
{
    if (DEBUG)
        std::cout << CYAN "[Assignment Operator]\t[Intern]\t" RESET;
	return *this;
}

// Functions
const t_form	Intern::FormTab[Intern::nbForm] = 
{
	{"ShrubberyCreationForm", &Intern::makeShrubForm},
	{"RobotomyRequestForm", &Intern::makeRobForm},
	{"PresidentialPardonForm", &Intern::makePresForm}
};

makeFunction	Intern::getFormFunct(std::string form)
{
	int i = 0;

	for (i = 0; i < Intern::nbForm; i++)
	{
		if (FormTab[i].fName.compare(form) == 0)
			return FormTab[i].fFunction;
	}
	return nullptr;
}

AForm*			Intern::makeForm(std::string form, std::string target)
{
	std::cout << CYAN "Intern creates \t[" << form << "|" << target << "]" RESET << std::endl;

	try
	{
		makeFunction fMakeForm;
		fMakeForm = getFormFunct(form);
		if (fMakeForm == nullptr)
			throw Intern::FormNotFound();
		return ((this->*(fMakeForm))(target));
	}
	catch (std::exception& e)
	{
		std::cerr << BOLDRED << ">> Intern couldn't make form " << form << " with target " << target << " because: " << e.what() << RESET << std::endl;
	}
	return nullptr;
}

AForm*			Intern::makeShrubForm(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm*			Intern::makeRobForm(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm*			Intern::makePresForm(std::string target)
{
	return (new PresidentialPardonForm(target));
}

// int				Intern::getFormIndex(std::string form)
// {
// 	int i = 0;

// 	for (i = 0; i < Intern::nbForm; i++)
// 	{
// 		if (FormTab[i].fName.compare(form) == 0)
// 			break;
// 	}
// 	return i;
// }

// option 2
		// {
		// 	switch (Intern::getFormIndex(form))
		// 	{
		// 		case 0:
		// 		{
		// 			std::cout << "a\n";
		// 			newForm = (this->*(FormTab[0].fFunction))(target);
		// 			break;
		// 		}
		// 		case 1:
		// 		{
		// 			std::cout << "b\n";
		// 			newForm = (this->*(FormTab[1].fFunction))(target);
		// 			break;
		// 		}
		// 		case 2:
		// 		{
		// 			std::cout << "c\n";
		// 			newForm = (this->*(FormTab[2].fFunction))(target);
		// 			break;
		// 		}    
		// 		default:
		// 		{
		// 			std::cout << "d\n";
			// 		throw Intern::FormNotFound();
		// 			break;
		// 		}
		// 	}
		// }
// option 3
		// {
		// 	if (form.compare("ShrubberyCreationForm") == 0)
		// 		newForm = this->makeShrubForm(target);
		// 	else if (form.compare("RobotomyRequestForm") == 0)
		// 		newForm = this->makeRobForm(target);
		// 	else if (form.compare("PresidentialPardonForm") == 0)
		// 		newForm = this->makePresForm(target);
		// 	else
		// 		throw Intern::FormNotFound();
		// }