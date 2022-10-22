#ifndef FRAGTRAP_CLASS_HPP
# define FRAGTRAP_CLASS_HPP

# include <iostream>
# include <string>

# include "colors.hpp"
# include "ClapTrap.class.hpp"

class FragTrap : public ClapTrap
{
    private:

    public:
    // FragTrap.class.cpp
                                FragTrap        ( void );
                                FragTrap        ( std::string name );
                                FragTrap        ( const FragTrap& src );
                                ~FragTrap       ( void );

        FragTrap &              operator=       ( const FragTrap & src );

    // FragTrap.function.class.cpp

        void                    highFivesGuys   (void);
        void                    attack          (const std::string& target);

};

std::ostream &      operator<<(std::ostream &o, FragTrap const &slapslap);

# endif
