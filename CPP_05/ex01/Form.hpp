#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <stdexcept>

# include "types.hpp"
# include "colors.hpp"
# include "Exceptions.hpp"
# include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string	_name;
		bool				_signed;
		int					_gradeToSign;
		int					_gradeToExec;

	public:
		// Constructors // Destructor
						Form			(void);
						Form			(const Form &copy);
						Form			(std::string name, int gradeToSign, int gradeToExec);
						~Form			(void);
		// Operators
		Form &			operator=		(const Form &assign);
		// Getters 
		std::string		getName			(void) const;
		int				getSigned		(void) const;
		int				getGradeToSign	(void) const;
		int				getGradeToExec	(void) const;
		// Setters
		void			setSigned		(bool s);
		void			setGradeToSign	(int gradeToSign);
		void			setGradeToExec	(int gradeToExec);
		// functions
		void			beSigned		(Bureaucrat &b);

		// Error management
		class GradeTooHigh: public GradeTooHighException {};
		class GradeTooLow: public GradeTooLowException {};

};

// Stream operators
std::ostream & 			operator<<	(std::ostream &stream, const Form &object);

#endif