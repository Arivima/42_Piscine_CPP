#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <fstream> 
# include <iostream>

# include "types.hpp"
# include "AForm.hpp"


class PresidentialPardonForm : public AForm
{
	protected:
		std::string					_target;
	public:
		// Constructors // Destructor
									PresidentialPardonForm		(void);
									PresidentialPardonForm		(const PresidentialPardonForm &copy);
									PresidentialPardonForm		(std::string target);
									~PresidentialPardonForm		(void);
		// Operators
		PresidentialPardonForm &	operator=					(const PresidentialPardonForm &assign);
		PresidentialPardonForm &	operator=					(const AForm &assign);
		// Getters 
		std::string					getTarget					(void) const;
		// Setters
		void						setTarget					(std::string target);
		// functions
		void						pardon						(Bureaucrat const &) const;
		void						executeDerived				(Bureaucrat const &) const;
};

// Stream operators
std::ostream &						operator<<					(std::ostream &stream, const PresidentialPardonForm &object);

#endif