#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

# include   <iostream>
# include   <string>

# include "colors.hpp"

class Fixed
{
    public:
                            Fixed(void);
                            Fixed(Fixed const & src);
                            ~Fixed(void);
        Fixed &             operator=(Fixed const & src);
        int                 getRawBits(void) const;
        void                setRawBits(int const raw);

    private:
        int                 _val;
        static const int    _nbBits = 8;
};

# endif
