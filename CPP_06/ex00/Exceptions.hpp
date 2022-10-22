#ifndef EXCEPTIONS_HPP
# define EXCEPTIONS_HPP

# include <iostream>
# include <string>
# include <stdexcept>

class Exceptions
{
	public:
	class WrongNbArgException: public std::exception
	{
		public:
			virtual const char * what () const throw()
			{
				return ("Wrong number of arguments. Please enter one argument.");
			}
	};
	class WrongInputException: public std::exception
	{
		public:
			virtual const char * what () const throw()
			{
				return ("Wrong input.");
			}
	};
	class CharNotPrintableException: public std::exception
	{
		public:
			virtual const char * what () const throw()
			{
				return ("Char is not printable.");
			}
	};
	class WrongInputIntException: public std::exception
	{
		public:
			virtual const char * what () const throw()
			{
				return ("Wrong input. Input is over Int limits");
			}
	};
	class WrongInputFloatException: public std::exception
	{
		public:
			virtual const char * what () const throw()
			{
				return ("Wrong input. Input is over Float limits");
			}
	};
	class WrongInputDoubleException: public std::exception
	{
		public:
			virtual const char * what () const throw()
			{
				return ("Wrong input. Input is over Double limits");
			}
	};

};

#endif
