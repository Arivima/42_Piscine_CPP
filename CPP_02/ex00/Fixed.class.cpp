# include "Fixed.class.hpp"

            Fixed::Fixed(void) : _val(0)
{
    std::cout <<  GREEN "[Default constructor called]" RESET <<  std::endl;
    return;
}

            Fixed::Fixed(Fixed const & src)
{
    std::cout <<  YELLOW "[Copy constructor called]" RESET <<  std::endl;
    *this = src;
    return;
}

            Fixed::~Fixed(void) 
{
    std::cout <<  RED "[Destructor called]" RESET <<  std::endl;
    return;
}

Fixed &     Fixed::operator=(Fixed const & src)
{
    std::cout <<  MAGENTA "[Copy assignment operator called]" RESET <<  std::endl;
	this->_val = src.getRawBits();
	return *this;
}

int         Fixed::getRawBits(void) const
{
    std::cout <<  CYAN "[getRawBits member function called]" RESET <<  std::endl;
	return this->_val;
}

void        Fixed::setRawBits(int const raw)
{
    this->_val = raw;
    return;
}
