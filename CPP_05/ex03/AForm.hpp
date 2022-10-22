#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include <stdexcept>

# include "types.hpp"
# include "colors.hpp"
# include "Exceptions.hpp"
# include "Bureaucrat.hpp"

class AForm
{
	protected:
		const std::string	_name;
		bool				_signed;
		int					_gradeToSign;
		int					_gradeToExec;

	public:
		// Constructors // Destructor
						AForm			(void);
						AForm			(const AForm &copy);
						AForm			(std::string name, int gradeToSign, int gradeToExec);
		virtual			~AForm			(void);
		// Operators
		virtual AForm &	operator=		(const AForm &assign);
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
		void			beSigned		(Bureaucrat const & b);
		void			execute			(Bureaucrat const & executor) const;
		virtual void	executeDerived	(Bureaucrat const & executor) const = 0;
		// Error management
		class GradeTooHigh: public GradeTooHighException {};
		class GradeTooLow: public GradeTooLowException {};
		class FormSigned: public FormSignedException {};
		class FormNotSigned: public FormNotSignedException {};
};

// Stream operators
std::ostream & 			operator<<	(std::ostream &stream, const AForm &object);

#endif