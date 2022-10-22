#ifndef WRONGCAT_CLASS_HPP
# define WRONGCAT_CLASS_HPP

# include <iostream>
# include <string>

# include "WrongAnimal.class.hpp"
# include "colors.hpp"

class WrongCat : public WrongAnimal
{
    protected:

    public:
                    WrongCat         ( void );
                    WrongCat         ( const WrongCat& src );
                    ~WrongCat        ( void );

        WrongCat &  operator=   ( const WrongCat & src );

        void        makeSound   (void) const;

};

std::ostream &      operator<<  (std::ostream &o, WrongCat const &object);

# endif
