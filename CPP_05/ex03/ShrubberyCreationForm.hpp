#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <fstream> 
# include <iostream>

# include "types.hpp"
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	protected:
		std::string					_target;
	public:
		// Constructors // Destructor
									ShrubberyCreationForm	(void);
									ShrubberyCreationForm	(const ShrubberyCreationForm &copy);
									ShrubberyCreationForm	(std::string target);
									~ShrubberyCreationForm	(void);
		// Operators
		ShrubberyCreationForm &		operator=				(const ShrubberyCreationForm &assign);
		ShrubberyCreationForm &		operator=				(const AForm &assign);
		// Getters 
		std::string					getTarget				(void) const;
		// Setters
		void						setTarget				(std::string target);
		// functions
		void						createShrub				(void) const;
		void						printShrub				(std::ofstream &stream) const;
		void						executeDerived			(Bureaucrat const &) const;
};

// Stream operators
std::ostream &						operator<<				(std::ostream &stream, const ShrubberyCreationForm &object);

#endif