#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include <stdexcept>

# include "types.hpp"
# include "colors.hpp"
# include "Exceptions.hpp"

# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

typedef	AForm*	(Intern::*makeFunction)	( std::string target );

typedef	struct	s_form
{
		std::string		fName;
		makeFunction	fFunction;
}				t_form;

class Intern
{
	private:
		AForm*			makeShrubForm	(std::string target);
		AForm*			makeRobForm		(std::string target);
		AForm*			makePresForm	(std::string target);
		makeFunction	getFormFunct	(std::string form);
		// int				getFormIndex	(std::string form);
	public:
		// attributes
		static const int		nbForm = 3;
		static const t_form		FormTab[nbForm];

		// Constructors // Destructor
						Intern	(void);
						Intern	(const Intern &copy);
						~Intern	(void);
		// Operators
		Intern &		operator=	(const Intern &assign);
		// Functions
		AForm*			makeForm	(std::string form, std::string target);
		// Exceptions
		class FormNotFound: public NotFoundException {};
};

#endif