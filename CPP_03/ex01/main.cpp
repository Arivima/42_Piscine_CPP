# include "ClapTrap.class.hpp"
# include "ScavTrap.class.hpp"

// default, copy, name, 
// = , <<
// use base functions(attack, takeDamage, beRepaired), var (_name)

int main( void ) 
{
    system("clear");
    std::cout << "------------- TEST MAIN SUBJECT " << std::endl;
    ClapTrap Clap1("Clap");
    std::cout << "-------------" << std::endl;
    ScavTrap Slap1("Slap");
    // std::cout << "-------------" << std::endl;
    // ScavTrap Slap2;
    // std::cout << "-------------" << std::endl;
    // Slap2 = Slap1;
    // std::cout << "-------------" << std::endl;
    // ScavTrap Slap3(Slap2);

    std::cout << "------------- Start fighting ! " << std::endl;

    std::cout << ".\t\t\t\t\t\t\t" << Clap1;
    std::cout << ".\t\t\t\t\t\t\t" << Slap1;
    Clap1.setAttackDamage(10);
    Slap1.setAttackDamage(7);
    Slap1.guardGate();
    for (int i = 0; i < 5; i++)
    {
        if (Slap1.checkLife() == 0)
            Clap1.attack("Slap");
        if (Clap1.checkLife() == 0)
            Slap1.takeDamage(Clap1.getAttackDamage());
        if (Clap1.checkLife() == 0)
            Slap1.attack("Clap");
        if (Slap1.checkLife() == 0)
            Clap1.takeDamage(Slap1.getAttackDamage());
    }
    Clap1.beRepaired(15);
    Slap1.beRepaired(500);

    std::cout << "------------- Game over ! " << std::endl;

    return 0;
}
