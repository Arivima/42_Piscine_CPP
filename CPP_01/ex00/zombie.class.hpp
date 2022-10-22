#ifndef ZOMBIE_CLASS_H
# define ZOMBIE_CLASS_H

# include <iostream>
# include <string>
# include "colors.hpp"

class Zombie
{
    public:
                    Zombie(std::string name);
                    ~Zombie(void);

        std::string ftGetName(void) const;
        void        ftAnnounce(void) const;

    private:
        std::string name;
};

#endif
