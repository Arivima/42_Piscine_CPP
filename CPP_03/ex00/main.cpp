# include "ClapTrap.class.hpp"

int main( void ) 
{
    system("clear");
    std::cout << "------------- TEST MAIN SUBJECT " << std::endl;
    ClapTrap Ding("Ding");
    ClapTrap Dong("Dong");
    ClapTrap Unknown;
    Unknown = Ding;
    ClapTrap Bob(Ding);

    std::cout << "------------- Start fighting ! " << std::endl;
    // for (int i = 0; i < 20; i++)
        Ding.attack("Dong");
        Dong.takeDamage(3);
        Dong.attack("Ding");
        Ding.takeDamage(10);
        Dong.beRepaired(15);
        Ding.beRepaired(5);
    std::cout << "------------- Game over ! " << std::endl;

    return 0;
}
