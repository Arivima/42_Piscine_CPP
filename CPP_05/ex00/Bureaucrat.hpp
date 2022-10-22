#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <stdexcept>

# include "colors.hpp"

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
		// Error management
		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char * what () const throw()
				{
					return ("Grade too high");
				}
		};
		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char * what () const throw()
				{
					return ("Grade too low");
				}
		};
};

// Stream operators
std::ostream & 			operator<<	(std::ostream &stream, const Bureaucrat &object);

#endif