#ifndef HUMANA_CLASS_H
# define HUMANA_CLASS_H

# include <iostream>
# include <string>
# include "colors.hpp"
# include "weapon.class.hpp"

class HumanA
{
    public:
                    HumanA(std::string nameStr, Weapon &weapon_typeStr);
                    ~HumanA(void);

        void        ftAttack() const;

    private:
        std::string name;
        Weapon      &weapon_type;
};

#endif
