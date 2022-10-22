#ifndef MATERIASOURCE_CLASS_HPP
# define MATERIASOURCE_CLASS_HPP

# include "IMateriaSource.class.hpp"
# include "types.class.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        AMateria *              _materias[4];

    public:
                                MateriaSource   (void);
                                MateriaSource   (const MateriaSource& src);
                                ~MateriaSource  (void);

        MateriaSource&          operator =      ( const MateriaSource& src );

        AMateria *              getMateria      (int i) const;
        void                    setMateria      (int i, AMateria * m);


        void                    learnMateria    (AMateria*);
        AMateria*               createMateria   (std::string const & type);
};

std::ostream &                  operator<<      (std::ostream &o, MateriaSource const &object);

# endif

