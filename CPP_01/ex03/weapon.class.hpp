#ifndef WEAPON_CLASS_H
# define WEAPON_CLASS_H

# include <iostream>
# include <string>
# include "colors.hpp"

class Weapon
{
    public:
                            Weapon(std::string typeStr);
                            Weapon(void);
                            ~Weapon(void);

        void                ftSetType(std::string newtype);
        std::string const   &ftGetType(void) const;

    private:
        std::string type;
};

#endif
