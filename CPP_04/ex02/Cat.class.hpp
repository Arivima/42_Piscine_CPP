#ifndef CAT_CLASS_HPP
# define CAT_CLASS_HPP

# include <iostream>
# include <string>

# include "colors.hpp"
# include "Animal.class.hpp"
# include "Brain.class.hpp"

class Cat : public Animal
{
    private:
        Brain*      _Brainp;
    public:
                    Cat         ( void );
                    Cat         ( const Cat& src );
                    ~Cat        ( void );

        Brain*      getBrainp(void) const;
        void        setBrainp(Brain* brainp);

        Cat &       operator=   ( const Cat & src );
        Cat &       operator=   ( const Animal & src );

        void        makeSound   (void) const;

};

std::ostream &      operator<<  (std::ostream &o, Cat const &object);

# endif
