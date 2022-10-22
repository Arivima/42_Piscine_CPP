#ifndef CAT_CLASS_HPP
# define CAT_CLASS_HPP

# include <iostream>
# include <string>

# include "Animal.class.hpp"
# include "colors.hpp"

class Cat : public Animal
{
    protected:

    public:
                    Cat         ( void );
                    Cat         ( const Cat& src );
                    ~Cat        ( void );

        Cat &       operator=   ( const Cat & src );

        void        makeSound   (void) const;

};

std::ostream &      operator<<  (std::ostream &o, Cat const &object);

# endif
