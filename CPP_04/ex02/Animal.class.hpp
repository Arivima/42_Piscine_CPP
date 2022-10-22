#ifndef ANIMAL_CLASS_HPP
# define ANIMAL_CLASS_HPP

# include <iostream>
# include <string>

# include "colors.hpp"

class Animal
{
    protected:
        std::string             _type;

    public:
                                Animal          ( void );
                                Animal          ( const Animal& src );
        virtual                 ~Animal         ( void );

        virtual Animal &        operator=       ( const Animal & src );

        std::string             getType         (void) const;
        void                    setType         (std::string type);

        virtual void            makeSound       (void) const = 0;

};

std::ostream &                  operator<<      (std::ostream &o, Animal const &object);

# endif
