#ifndef HUMANB_CLASS_H
# define HUMANB_CLASS_H

# include <iostream>
# include <string>
# include "colors.hpp"
# include "weapon.class.hpp"

class HumanB
{
    public:
                    HumanB(std::string nameStr);
                    ~HumanB(void);

        void        ftAttack() const;
        void        ftSetWeapon(Weapon &newWeapon);

    private:
        std::string name;
        Weapon      *weapon_type;
};

#endif
