# include "ClapTrap.class.hpp"
# include "ScavTrap.class.hpp"
# include "FragTrap.class.hpp"
# include "DiamondTrap.class.hpp"

// default, copy, name, 
// = , <<
// use base functions(attack, takeDamage, beRepaired), var (_name)

int main( void ) 
{
    system("clear");
    std::cout << "------------- STARTING TEST EX03 " << std::endl;
    if (DEBUG)
    {
        std::cout << "------------- TEST CONSTRUCTOR " << std::endl;
        DiamondTrap NameA("NameA");
        std::cout << "------------- " << std::endl;
        DiamondTrap NameB("NameB");
        std::cout << "------------- " << std::endl;
        DiamondTrap Default;
        std::cout << "------------- " << std::endl;
        DiamondTrap Copy(NameA);
        std::cout << "------------- = operator " << std::endl;
        std::cout << "Default:" << Default;
        std::cout << "NameB:  "<< NameB;
        Default = NameB;
        std::cout << "Default:" << Default;
        std::cout << "NameB:  "<< NameB;
        std::cout << "------------- << operator " << std::endl;
        std::cout << "NameA:  " << NameA;
        std::cout << "NameB:  "<< NameB;
        std::cout << "Default:" << Default;
        std::cout << "Copy:   "<< Copy;
    }
    {
        std::cout << "------------- TEST functions " << std::endl;
        DiamondTrap Diam1("Daenerys");
        DiamondTrap Diam2("Rhaenyra");
        Diam1.whoAmI();
        Diam2.whoAmI();
        Diam1.guardGate();
        Diam1.highFivesGuys();
        std::cout << BOLDWHITE "------------- Start fighting ! " RESET << std::endl;
        std::cout << "Contestant\t\t\t\t\t\t\t\t" << Diam1;
        std::cout << "Contestant\t\t\t\t\t\t\t\t" << Diam2;

        for (int i = 0; i < 6; i++)
        {
            if (Diam1.checkLife() == 0)
            {
                if (Diam2.checkLife() == 0)
                {
                    Diam1.attack("Rhaenyra");
                    Diam2.takeDamage(Diam1.getAttackDamage());
                }
            }
        }

        Diam2.beRepaired(200);
    }
        std::cout << "------------- Game over ! " << std::endl;

    return 0;
}
