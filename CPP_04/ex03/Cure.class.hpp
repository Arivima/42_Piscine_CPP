#ifndef CURE_CLASS_HPP
# define CURE_CLASS_HPP

# include "AMateria.class.hpp"
# include "types.class.hpp"

class Cure : public AMateria
{
    public:
        int             id; // for debug

                        Cure        (void);
                        Cure        (const Cure & src);
                        ~Cure       (void);

        Cure &          operator=   (const Cure & src);

        AMateria*       clone       (void) const; // attention type retour
        void            use         (ICharacter& target);
};

std::ostream &          operator<<  (std::ostream &o, Cure const &object);

# endif