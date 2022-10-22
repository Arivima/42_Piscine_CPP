# include "Fixed.class.hpp"

float               Fixed::toFloat( void ) const
{
    // std::cout << "toFloat called" << std::endl;
    return ((float)this->_val / (1 << _nbBits));
}

int                 Fixed::toInt( void ) const
{
    // std::cout << "toInt called" << std::endl;
    return this->_val >> _nbBits;
}

int                 Fixed::getRawBits( void ) const
{
    return this->_val;
}

void                Fixed::setRawBits( int const raw )
{
    // std::cout << "setRawBits called" << std::endl;
    this->_val = raw;
    return;
}

Fixed &             Fixed::min( Fixed & a, Fixed & b )
{
    if (a._val < b._val)
        return a;
    return b;
}

const Fixed &       Fixed::min( const Fixed & a, const Fixed & b )
{
    if (a._val < b._val)
        return a;
    return b;   
}

Fixed &             Fixed::max( Fixed & a, Fixed & b )
{
    if (a._val > b._val)
        return a;
    return b;
}

const Fixed &       Fixed::max( const Fixed & a, const Fixed & b )
{
    if (a._val > b._val)
        return a;
    return b;   
}