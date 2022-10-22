# include "ex00.hpp"

void        ftRandomChump(std::string name)
{
    std::cout << YELLOW ;

    Zombie  myzombie(name);
    myzombie.ftAnnounce();

    std::cout << RESET;
    return;
}