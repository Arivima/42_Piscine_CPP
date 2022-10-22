# include "Fixed.class.hpp"

                    Fixed::Fixed(void) : _val(0)
{
    // std::cout << "Default constructor called\t| val: " << _val << std::endl;
    return ;
}

                    Fixed::Fixed(const Fixed& src)
{
    *this = src;
    // std::cout << "Copy constructor called  \t| val: " << _val  << std::endl;
    return ;
}

                    Fixed::Fixed(const int n)
{
    this->_val = n << _nbBits;
    // std::cout << "Int constructor called    \t| n: " << n << " \t| val: " << _val << std::endl;
    return ;
}

                    Fixed::Fixed(const float f)
{
    this->_val = roundf(f * (1 << _nbBits));
    // std::cout << "Float constructor called\t| f: " << f << " \t| val: " << _val  << std::endl;
    return ;
}

                    Fixed::~Fixed(void)
{
    // std::cout << "Destructor called" << std::endl;
    return;
}
