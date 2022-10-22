#ifndef EXCEPTIONS_HPP
# define EXCEPTIONS_HPP

# include <iostream>
# include <string>
# include <stdexcept>

# include "colors.hpp"

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


#endif