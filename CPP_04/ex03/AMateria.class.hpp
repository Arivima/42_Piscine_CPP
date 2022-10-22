#ifndef AMATERIA_CLASS_HPP
# define AMATERIA_CLASS_HPP

# include <iostream>
# include <string>

# include "colors.hpp"

# include "ICharacter.class.hpp"
# include "types.class.hpp"

class AMateria
{
    protected:
        std::string   _type;
    public:
        int                 ID; // for debug

                            AMateria    (std::string const & type);
                            AMateria    (const AMateria & src);
                            AMateria    (void);
        virtual             ~AMateria   (void);

        virtual AMateria &  operator=   (const AMateria & src);

        std::string const & getType     (void) const;
        void                setType     (std::string const type);

        virtual AMateria*   clone       (void) const = 0;
        virtual void        use         (ICharacter& target);
};

std::ostream &              operator<<  (std::ostream &o, AMateria const &object);

# endif