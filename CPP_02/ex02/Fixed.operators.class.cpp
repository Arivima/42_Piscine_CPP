# include "Fixed.class.hpp"

std::ostream &      operator<<(std::ostream &o, Fixed const &fx)
{
	o << fx.toFloat();
	return o;
}

Fixed &             Fixed::operator=(const Fixed & src)
{
    // std::cout << "Copy assignment operator called" << std::endl;
    this->_val = src.getRawBits();
    return *this;
}
