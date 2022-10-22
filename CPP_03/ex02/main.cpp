# include "ClapTrap.class.hpp"
# include "ScavTrap.class.hpp"
# include "FragTrap.class.hpp"

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
    std::cout << "-------------" << std::endl;
    FragTrap Flap1("Flap");

    std::cout << "------------- Start fighting ! " << std::endl;

    std::cout << ".\t\t\t\t\t\t\t" << Clap1;
    std::cout << ".\t\t\t\t\t\t\t" << Slap1;
    std::cout << ".\t\t\t\t\t\t\t" << Flap1;

    Slap1.guardGate();
    for (int i = 0; i < 3; i++)
    {
        if (Clap1.checkLife() == 0)
        {
            if (Slap1.checkLife() == 0)
            {
                Clap1.attack("Slap");
                Slap1.takeDamage(Clap1.getAttackDamage());
            }
            if (Flap1.checkLife() == 0)
            {
                Clap1.attack("Flap");
                Flap1.takeDamage(Clap1.getAttackDamage());
            }            
        }
        if (Slap1.checkLife() == 0)
        {
            if (Flap1.checkLife() == 0)
            {
                Slap1.attack("Flap");
                Flap1.takeDamage(Slap1.getAttackDamage());
            }
            if (Clap1.checkLife() == 0)
            {
                Slap1.attack("Clap");
                Clap1.takeDamage(Slap1.getAttackDamage());
            }            
        }
        if (Flap1.checkLife() == 0)
        {
            Flap1.highFivesGuys();
            if (Slap1.checkLife() == 0)
            {
                Flap1.attack("Slap");
                Slap1.takeDamage(Flap1.getAttackDamage());
            }
            if (Clap1.checkLife() == 0)
            {
                Flap1.attack("Clap");
                Clap1.takeDamage(Flap1.getAttackDamage());
            }            
        }

    }
    Clap1.beRepaired(15);
    Slap1.beRepaired(500);
    Flap1.beRepaired(200);

    std::cout << "------------- Game over ! " << std::endl;

    return 0;
}
