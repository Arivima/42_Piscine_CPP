#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <stdexcept>

# include "types.hpp"
# include "colors.hpp"
# include "Exceptions.hpp"
# include "AForm.hpp"

class Bureaucrat
{
	private:
		const std::string		_name;
		int				_grade;

	public:
		// Constructors // Destructor
						Bureaucrat	(void);
						Bureaucrat	(const Bureaucrat &copy);
						Bureaucrat	(std::string _name, int _grade);
						~Bureaucrat	(void);
		// Operators
		Bureaucrat &	operator=	(const Bureaucrat &assign);
		// Getters / Setters
		std::string		getName		(void) const;
		int				getGrade	(void) const;
		void			setGrade	(int grade);
		// Incrementation, decrementation
		void			incrGrade	(void);
		void			decrGrade	(void);
		// Functions
		void			signForm	(AForm &form);
		void			executeForm	(AForm const & form);
		// Error management
		class GradeTooHigh: public GradeTooHighException {};
		class GradeTooLow: public GradeTooLowException {};
};

// Stream operators
std::ostream & 			operator<<	(std::ostream &stream, const Bureaucrat &object);

#endif