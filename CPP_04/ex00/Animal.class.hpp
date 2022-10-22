#ifndef ANIMAL_CLASS_HPP
# define ANIMAL_CLASS_HPP

# include <iostream>
# include <string>

# include "colors.hpp"

# define DEBUG 1

class Animal
{
    protected:
        std::string     _type;

    public:
                        Animal          ( void );
                        Animal          ( const Animal& src );
                        ~Animal         ( void );

        Animal &        operator=       ( const Animal & src );

        std::string     getType         (void) const;
        void            setType         (std::string type);

        void virtual    makeSound       (void) const;

};

std::ostream &          operator<<      (std::ostream &o, Animal const &object);

# endif
