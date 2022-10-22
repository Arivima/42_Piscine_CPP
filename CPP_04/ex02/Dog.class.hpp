#ifndef DOG_CLASS_HPP
# define DOG_CLASS_HPP

# include <iostream>
# include <string>

# include "colors.hpp"
# include "Animal.class.hpp"
# include "Brain.class.hpp"

class Dog : public Animal
{
    private:
        Brain*          _Brainp;
    public:
                        Dog         ( void );
                        Dog         ( const Dog& src );
                        ~Dog        ( void );

        Brain*          getBrainp(void) const;
        void            setBrainp(Brain* brainp);

        Dog &           operator=   ( const Dog & src );
        Dog &           operator=   ( const Animal & src );

        void            makeSound   (void) const;

};

std::ostream &          operator<<  (std::ostream &o, Dog const &object);

# endif
