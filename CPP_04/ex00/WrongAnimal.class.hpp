#ifndef WRONGANIMAL_CLASS_HPP
# define WRONGANIMAL_CLASS_HPP

# include <iostream>
# include <string>

# include "colors.hpp"

# define DEBUG 1

class WrongAnimal
{
    protected:
        std::string     _type;

    public:
                        WrongAnimal          ( void );
                        WrongAnimal          ( const WrongAnimal& src );
                        ~WrongAnimal         ( void );

        WrongAnimal &        operator=       ( const WrongAnimal & src );

        std::string     getType         (void) const;
        void            setType         (std::string type);

        void            makeSound       (void) const;

};

std::ostream &          operator<<      (std::ostream &o, WrongAnimal const &object);

# endif
