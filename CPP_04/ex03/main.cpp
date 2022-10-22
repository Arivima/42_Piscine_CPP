# include "types.class.hpp"
# include "Character.class.hpp"
# include "MateriaSource.class.hpp"
# include "Ice.class.hpp"
# include "Cure.class.hpp"

// basics: default, copy, string, destructor, assignment operator, outstream operator
// functions


int main( void ) 
{
    // std::cout << "------------- STARTING TEST EX03 " << std::endl;
    // {
    //     IMateriaSource* src = new MateriaSource();
    //     IMateriaSource* dst = new MateriaSource();
    //     MateriaSource* ex = new MateriaSource();
    //     Ice* ice = new Ice();
    //     AMateria* ICE = new Ice();
    //     Cure* cure = new Cure();
    //     AMateria* CURE = new Cure();
    //     std::cout << src << std::endl;
    //     std::cout << dst << std::endl;
    //     std::cout << ex << std::endl;
    //     ex->learnMateria(0);
    //     ex->learnMateria(ice);
    //     ex->learnMateria(ICE);
    //     ex->learnMateria(cure);
    //     ex->learnMateria(CURE);
    //     ex->learnMateria(ice);
    //     std::cout << *ex << std::endl;
    //     AMateria* newice = ex->createMateria("ice");
    //     std::cout << *newice << std::endl;
    //     _delete(newice);
    //     _delete(src);
    //     _delete(dst);
    //     _delete(ex);
    //     _delete(ice);
    //     _delete(ICE);
    //     _delete(cure);
    //     _delete(CURE);
    // }
    {
        std::cout << "------------- TEST LEAKS " << std::endl;
        std::cout << "------------- new materia " << std::endl;
        int     m_nb = 6;
        AMateria *materia [m_nb];
        for (int i = 0; i < m_nb; i++)
        {
            if (i % 2)
                materia [i] = new Ice;
            else
                materia [i] = new Cure;
        }
        std::cout << BOLDWHITE"------------- new character " RESET << std::endl;
        Character *Jacques = new Character("Jacques");
        Character *Jean = new Character("Jean");
        
        std::cout << BOLDWHITE"------------- EQUIP" RESET << std::endl;
        std::cout << "jacs " << *Jacques << std::endl << "jean " <<*Jean << std::endl;
        for (int i = 0; i < m_nb; i++)
            Jacques->equip(materia[i]);
        for (int i = 2; i < m_nb; i++)
            Jean->equip(materia[i]);
        std::cout << "jacs " << *Jacques << std::endl << "jean " <<*Jean << std::endl;

        std::cout << BOLDWHITE "------------- UNEQUIP (LISTS)" RESET << std::endl;
        std::cout << "jacs " << *Jacques << std::endl << "jean " <<*Jean << std::endl;
        for (int i = 0; i < 3; i++)
            Jacques->unequip(i);
        std::cout << "jacs " << *Jacques << std::endl << "jean " <<*Jean << std::endl;

        std::cout << BOLDWHITE "------------- ASSIGN" RESET << std::endl;
        std::cout << "jacs " << *Jacques << std::endl << "jean " <<*Jean << std::endl;
        *Jean = *Jacques;
        // *Jacques = *Jean;
        std::cout << "jacs " << *Jacques << std::endl << "jean " <<*Jean << std::endl;

        std::cout << BOLDWHITE "------------- USE" RESET << std::endl;
        Jacques->use(0, *Jean);
        Jacques->use(3, *Jean);
        Jean->use(3, *Jacques);

        std::cout << BOLDWHITE"------------- DELETE " RESET << std::endl;
        std::cout << "Deleting Main materia" << std::endl;
        for (int i = 0; i < m_nb; i++)
            _delete(materia[i]);
        std::cout << "Deleting Characters" << std::endl;
        std::cout << "jacs " << *Jacques << std::endl << "jean " <<*Jean << std::endl;
        std::cout << "Deleting Jacques" << std::endl;
        _delete(Jacques);
        std::cout << "Deleting Jean" << std::endl;
        _delete(Jean);
        std::cout << "jacs " << Jacques << std::endl << "jean " <<Jean << std::endl;
    }
    std::cout << BOLDWHITE"------------- Game over ! " RESET << std::endl;

    // {
    //     std::cout << "IMateriaSource* src = new MateriaSource();" << std::endl;
    //     IMateriaSource* src = new MateriaSource();

    //     std::cout << "src->learnMateria(new Ice());" << std::endl;
    //     AMateria * newIce = new Ice();
    //     src->learnMateria(newIce);

    //     std::cout << "src->learnMateria(new Cure());" << std::endl;
    //     AMateria * newCure = new Cure();
    //     src->learnMateria(newCure);

    //     std::cout << "ICharacter* me = new Character(\"me\");" << std::endl;
    //     ICharacter* me = new Character("me");

    //     std::cout << "AMateria* tmp;" << std::endl;
    //     AMateria* tmp;

    //     std::cout << "tmp = src->createMateria(\"ice\");" << std::endl;
    //     tmp = src->createMateria("ice");

    //     std::cout << "me->equip(tmp);" << std::endl;
    //     me->equip(tmp);

    //     _delete(tmp);
    //     std::cout << "tmp = src->createMateria(\"cure\");" << std::endl;
    //     tmp = src->createMateria("cure");
    //     std::cout << "me->equip(tmp);" << std::endl;
    //     me->equip(tmp);
    //     _delete(tmp);

    //     std::cout << "ICharacter* bob = new Character(\"bob\");" << std::endl;
    //     ICharacter* bob = new Character("bob");

    //     std::cout << " me->use(0, *bob);" << std::endl;
    //     me->use(0, *bob);

    //     std::cout << "me->use(1, *bob);" << std::endl;
    //     me->use(1, *bob);
    //     _delete(newIce);
    //     _delete(newCure);

    //     std::cout << "delete bob;" << std::endl;
    //     delete bob;

    //     std::cout << "delete me;" << std::endl;
    //     delete me;
        
    //     std::cout << "delete src;" << std::endl;
    //     delete src;
    // }
    return 0;
}