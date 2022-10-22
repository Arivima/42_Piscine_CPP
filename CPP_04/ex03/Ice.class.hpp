#ifndef ICE_CLASS_HPP
# define ICE_CLASS_HPP

# include "AMateria.class.hpp"
# include "types.class.hpp"

class Ice : public AMateria
{
    public:
        int                 id; // for debug

                            Ice         (void);
                            Ice         (const Ice & src);
                            ~Ice        (void);

        Ice &               operator=   (const Ice & src);

        AMateria*           clone       (void) const;
        void                use         (ICharacter& target);
};

std::ostream &              operator<<  (std::ostream &o, Ice const &object);

# endif