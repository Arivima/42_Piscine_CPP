#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <fstream> 
# include <iostream>

# include "types.hpp"
# include "AForm.hpp"


class RobotomyRequestForm : public AForm
{
	protected:
		std::string					_target;
	public:
		// Constructors // Destructor
									RobotomyRequestForm		(void);
									RobotomyRequestForm		(const RobotomyRequestForm &copy);
									RobotomyRequestForm		(std::string target);
									~RobotomyRequestForm	(void);
		// Operators
		RobotomyRequestForm &		operator=				(const RobotomyRequestForm &assign);
		RobotomyRequestForm &		operator=				(const AForm &assign);
		// Getters 
		std::string					getTarget				(void) const;
		// Setters
		void						setTarget				(std::string target);
		// functions
		void						Robotomize				(Bureaucrat const &) const;
		void						executeDerived			(Bureaucrat const &) const;
};

// Stream operators
std::ostream &						operator<<				(std::ostream &stream, const RobotomyRequestForm &object);

#endif