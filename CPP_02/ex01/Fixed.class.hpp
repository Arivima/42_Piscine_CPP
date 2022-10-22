#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

# include <iostream>
# include <string>
# include <cmath>

# include "colors.hpp"

class Fixed
{
    private:
        int                 _val;
        static const int    _nbBits = 8;

    public:
                            Fixed       ( void );
                            Fixed       ( const Fixed& src );
                            Fixed       ( const int n );
                            Fixed       ( const float f );
                            ~Fixed      ( void );
        Fixed &             operator=   ( const Fixed & src );
        int                 getRawBits  ( void ) const;
        void                setRawBits  ( int const raw );
        float               toFloat     ( void ) const;
        int                 toInt       ( void ) const;
};

std::ostream &      operator<<( std::ostream & o, Fixed const & src );

# endif