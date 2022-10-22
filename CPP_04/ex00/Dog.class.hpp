#ifndef DOG_CLASS_HPP
# define DOG_CLASS_HPP

# include <iostream>
# include <string>

# include "Animal.class.hpp"
# include "colors.hpp"

class Dog : public Animal
{
    protected:

    public:
                    Dog         ( void );
                    Dog         ( const Dog& src );
                    ~Dog        ( void );

        Dog &       operator=   ( const Dog & src );

        void        makeSound   (void) const;

};

std::ostream &      operator<<  (std::ostream &o, Dog const &object);

# endif
