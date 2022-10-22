#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

# include <iostream>
# include <string>
# include <cmath>


class Fixed
{
    private:
        int                     _val;
        static const int        _nbBits = 8;

    public:
    // Fixed.class.cpp
                                Fixed       ( void );
                                Fixed       ( const Fixed& src );
                                Fixed       ( const int n );
                                Fixed       ( const float f );
                                ~Fixed      ( void );

    // Fixed.function.class.cpp
        int                     getRawBits  ( void ) const;
        void                    setRawBits  ( int const raw );
        float                   toFloat     ( void ) const;
        int                     toInt       ( void ) const;

        static Fixed &          min         ( Fixed & a, Fixed & b );
        static const Fixed &    min         ( const Fixed & a, const Fixed & b );
        static Fixed &          max         ( Fixed & a, Fixed & b );
        static const Fixed &    max         ( const Fixed & a, const Fixed & b );

    // Fixed.operators.class.cpp
        Fixed &                 operator=   ( const Fixed & src );

    // Fixed.arithm_operators.class.cpp
        const Fixed             operator+   ( const Fixed & src ) const;
        const Fixed             operator-   ( const Fixed & src ) const;
        const Fixed             operator*   ( const Fixed & src ) const;
        const Fixed             operator/   ( const Fixed & src ) const;

        Fixed &                 operator++  ( void ) ;
        const Fixed             operator++  ( int ) ;
        Fixed &                 operator--  ( void ) ;
        const Fixed             operator--  ( int ) ;

    // Fixed.cond_operators.class.cpp
        bool                    operator>   ( const Fixed & src ) const;
        bool                    operator<   ( const Fixed & src ) const;
        bool                    operator>=  ( const Fixed & src ) const;
        bool                    operator<=  ( const Fixed & src ) const;
        bool                    operator==  ( const Fixed & src ) const;
        bool                    operator!=  ( const Fixed & src ) const;
};

// Fixed.operators.class.cpp
std::ostream &      operator<<( std::ostream & o, Fixed const & src );

# endif