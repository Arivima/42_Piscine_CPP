#ifndef EXCEPTIONS_HPP
# define EXCEPTIONS_HPP

# include <iostream>
# include <string>
# include <stdexcept>

class Exceptions
{
	public:
	class OutOfRangeException: public std::exception
	{
		public:
			virtual const char * what () const throw()
			{
				return ("Out of range access to element. Invalid index.");
			}
	};
};

#endif
