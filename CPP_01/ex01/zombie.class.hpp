#ifndef ZOMBIE_CLASS_H
# define ZOMBIE_CLASS_H

# include <iostream>
# include <string>
# include "colors.hpp"

class Zombie
{
    public:
                    Zombie(void);
                    ~Zombie(void);

        void        ftSetName(std::string str);
        std::string ftGetName(void) const;
        void        ftAnnounce(void) const;

    private:
        std::string name;
};

#endif
