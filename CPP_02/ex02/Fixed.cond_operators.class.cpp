# include "Fixed.class.hpp"

bool                 Fixed::operator<(const Fixed & src) const
{
    // std::cout << "< operator called" << std::endl;
    return this->_val < src.getRawBits();
}

bool                 Fixed::operator>(const Fixed & src) const
{
    // std::cout << "> operator called" << std::endl;
    return this->_val > src.getRawBits();
}

bool                 Fixed::operator<=(const Fixed & src) const
{
    // std::cout << "<= operator called" << std::endl;
    return this->_val <= src.getRawBits();
}

bool                 Fixed::operator>=(const Fixed & src) const
{
    // std::cout << ">= operator called" << std::endl;
    return this->_val >= src.getRawBits();
}

bool                 Fixed::operator==(const Fixed & src) const
{
    // std::cout << "== operator called" << std::endl;
    return this->_val == src.getRawBits();
}

bool                 Fixed::operator!=(const Fixed & src) const
{
    // std::cout << "!= operator called" << std::endl;
    return this->_val != src.getRawBits();
}
