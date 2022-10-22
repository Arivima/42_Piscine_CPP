#ifndef CLAPTRAP_CLASS_HPP
# define CLAPTRAP_CLASS_HPP

# include <iostream>
# include <string>

# include "colors.hpp"

class ClapTrap
{
    private:
        std::string             _name;
        int                     _hitPoints;
        int                     _energyPoints;
        int                     _attackDamage;

    public:
    // ClapTrap.class.cpp
                                ClapTrap        ( void );
                                ClapTrap        ( std::string name );
                                ClapTrap        ( const ClapTrap& src );
                                ~ClapTrap       ( void );

        ClapTrap &              operator=       ( const ClapTrap & src );

    // ClapTrap.function.class.cpp
        std::string             getName         (void) const;
        int                     getAttackDamage (void) const;
        int                     getEnergyPoints (void) const;
        int                     getHitPoints    (void) const;

        void                    setName         (std::string name);
        void                    setAttackDamage (int n);
        void                    setEnergyPoints (int n);
        void                    setHitPoints    (int n);

        void                    attack          (const std::string& target);
        void                    takeDamage      (unsigned int amount);
        void                    beRepaired      (unsigned int amount);

};

std::ostream &      operator<<(std::ostream &o, ClapTrap const &clapclap);

# endif
