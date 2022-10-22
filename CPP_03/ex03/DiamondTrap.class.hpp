#ifndef DiamondTrap_CLASS_HPP
# define DiamondTrap_CLASS_HPP

# include <iostream>
# include <string>

# include "colors.hpp"
# include "ScavTrap.class.hpp"
# include "FragTrap.class.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
    private:
        std::string             _name;
    public:
                                DiamondTrap     ( void );
                                DiamondTrap     ( std::string name );
                                DiamondTrap     ( const DiamondTrap& src );
                                ~DiamondTrap    ( void );

        DiamondTrap &           operator=       ( const DiamondTrap & src );

        std::string             getName         (void) const;
        std::string             getClapName     (void) const;
        void                    setName         (std::string name);
        void                    setClapName     (std::string name);

        void                    whoAmI          (void);
        void                    attack          (const std::string& target);

};

std::ostream &                  operator<<      (std::ostream &o, DiamondTrap const &slapslap);

# endif

