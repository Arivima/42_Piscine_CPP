#ifndef SCAVTRAP_CLASS_HPP
# define SCAVTRAP_CLASS_HPP

# include <iostream>
# include <string>

# include "colors.hpp"
# include "ClapTrap.class.hpp"

class ScavTrap :  public virtual ClapTrap
{
    private:
        bool                    _gateKeeperMode;

    public:
                                ScavTrap        ( void );
                                ScavTrap        ( std::string name );
                                ScavTrap        ( const ScavTrap& src );
                                ~ScavTrap       ( void );

        ScavTrap &              operator=       ( const ScavTrap & src );

        bool                    getMode(void) const;
        void                    setMode(bool mode);

        void                    guardGate       (void);
        void                    attack          (const std::string& target);
};

std::ostream &                  operator<<      (std::ostream &o, ScavTrap const &slapslap);

# endif
