# include "Fixed.class.hpp"

                    Fixed::Fixed(void) : _val(0)
{
    std::cout << "Default constructor called" << std::endl;
    return ;
}

                    Fixed::Fixed(const Fixed& src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
    return ;
}

                    Fixed::Fixed(const int n)
{
    this->_val = n << _nbBits;
    std::cout << "Int constructor called" << std::endl;
    return ;
}

                    Fixed::Fixed(const float f)
{
    // this->_val = roundf((int )f << _nbBits); // ICI arielle
    this->_val = roundf(f * (1 << _nbBits)); // ICI
    std::cout << "Float constructor called" << std::endl;
    return ;
}

                    Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
    return;
}

// ICI
std::ostream &	operator<<(std::ostream &o, Fixed const &fx)
{
	o << fx.toFloat();
	return o;
}

// ICI
Fixed &             Fixed::operator=(const Fixed & src)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->_val = src.getRawBits();
    return *this;
}

int                 Fixed::getRawBits( void ) const
{
    return this->_val;
}

void                Fixed::setRawBits( int const raw )
{
    this->_val = raw;
    return;
}

float                 Fixed::toFloat( void ) const
{
    return ((float)this->_val / (1 << _nbBits));;
    // return ((float)(this->_val >> _nbBits)); // ICI arielle
}

int                 Fixed::toInt( void ) const
{
    return this->_val >> _nbBits;
}