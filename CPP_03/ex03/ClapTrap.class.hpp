#ifndef CLAPTRAP_CLASS_HPP
# define CLAPTRAP_CLASS_HPP

# include <iostream>
# include <string>

# include "colors.hpp"

# define DEBUG 1

class ClapTrap
{
    protected:
        std::string             _name;
        int                     _hitPoints;
        int                     _maxHitPoints;
        int                     _energyPoints;
        int                     _attackDamage;

    public:
                                ClapTrap        ( void );
                                ClapTrap        ( std::string name );
                                ClapTrap        ( const ClapTrap& src );
                                ~ClapTrap       ( void );

        ClapTrap &              operator=       ( const ClapTrap & src );

        std::string             getName         (void) const;
        int                     getAttackDamage (void) const;
        int                     getEnergyPoints (void) const;
        int                     getHitPoints    (void) const;
        int                     getMaxHitPoints (void) const;

        void                    setName         (std::string name);
        void                    setAttackDamage (int n);
        void                    setEnergyPoints (int n);
        void                    setHitPoints    (int n);

        void                    attack          (const std::string& target);
        void                    takeDamage      (unsigned int amount);
        void                    beRepaired      (unsigned int amount);

        bool                    checkLife       (void) const;

};

std::ostream &      operator<<(std::ostream &o, ClapTrap const &clapclap);

# endif
