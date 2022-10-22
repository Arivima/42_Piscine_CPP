#ifndef EXCEPTIONS_HPP
# define EXCEPTIONS_HPP

# include <iostream>
# include <string>
# include <stdexcept>

# include "colors.hpp"

// AForm
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
class FormSignedException: public std::exception
{
	public:
		virtual const char * what () const throw()
		{
			return ("Form is already signed");
		}
};
class FormNotSignedException: public std::exception
{
	public:
		virtual const char * what () const throw()
		{
			return ("Form hasn't been signed yet");
		}
};
// Intern
class NotFoundException: public std::exception
{
	public:
		virtual const char * what () const throw()
		{
			return ("Form not found !");
		}
};
// Robotomy
class RobotomyFailedException: public std::exception
{
	public:
		virtual const char * what () const throw()
		{
			return (">> Robotomy attempt has failed");
		}
};

#endif

