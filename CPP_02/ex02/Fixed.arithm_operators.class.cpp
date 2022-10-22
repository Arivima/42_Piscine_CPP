# include "Fixed.class.hpp"

const Fixed               Fixed::operator+( const Fixed & src ) const
{
    // std::cout << "+ operator called" << std::endl;
    Fixed dst;
    dst.setRawBits(this->_val + src.getRawBits());
    return dst;
}

const Fixed               Fixed::operator-( const Fixed & src ) const
{
    // std::cout << "- operator called" << std::endl;
    Fixed dst;
    dst.setRawBits(this->_val - src.getRawBits());
    return dst;
}

const Fixed               Fixed::operator*( const Fixed & src ) const
{
    // std::cout << "* operator called" << std::endl;
    Fixed dst;
    dst.setRawBits(this->_val * src.getRawBits() >> _nbBits);
    return dst;
}

const Fixed               Fixed::operator/( const Fixed & src ) const
{
    // std::cout << "/ operator called" << std::endl;
    Fixed dst;
    dst.setRawBits((this->_val << _nbBits) / src.getRawBits());
    return dst;
}

Fixed &             Fixed::operator++( void )
{
    // std::cout << "++Fixed operator called " << std::endl;
    this->setRawBits(this->getRawBits() + 1);
    return (*this);
}

const Fixed            Fixed::operator++( int )
{
    // std::cout << "Fixed++ operator called " << std::endl;
    Fixed   tmp = *this;
    this->setRawBits(this->getRawBits() + 1);
    return (tmp);
}

Fixed &             Fixed::operator--( void )
{
    // std::cout << "++Fixed operator called " << std::endl;
    this->setRawBits(this->getRawBits() - 1);
    return (*this);
}

const Fixed            Fixed::operator--( int )
{
    // std::cout << "Fixed++ operator called " << std::endl;
    Fixed   tmp = *this;
    this->setRawBits(this->getRawBits() - 1);
    return (tmp);
}