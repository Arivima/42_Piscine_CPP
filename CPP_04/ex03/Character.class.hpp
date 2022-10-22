#ifndef CHARACTER_CLASS_HPP
# define CHARACTER_CLASS_HPP

# include "types.class.hpp"
# include "ICharacter.class.hpp"
# include "utils_list.hpp"

class Character : public ICharacter
{
    private:
        std::string         _name;
        AMateria *          _inventory[4];

    public:
        t_list *            wasteList;

                            Character   (void);
                            Character   (std::string const & name);
                            Character   (const Character & src);
                            ~Character  (void);

        Character &         operator=   (const Character & src);

        std::string const & getName     (void) const;
        AMateria *          getInventory (int i) const;
        void                setName     (std::string const & name);
        void                setInventory (int i, AMateria * m);
        void                equip       (AMateria* m);
        void                unequip     (int idx);
        void                use         (int idx, ICharacter& target);
};

std::ostream &              operator<<  (std::ostream &o, Character const &object);

# endif