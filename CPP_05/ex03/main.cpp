# include "Bureaucrat.hpp"
# include "Intern.hpp"
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

// basics: default, copy, string, destructor, assignment operator, outstream operator
// functions

int main( void ) 
{
    std::cout << BOLDWHITE "------------- STARTING TEST CPP05_EX00 " RESET << std::endl;
    {
        std::cout << BOLDWHITE "------------- [INTERN] [TEST CLASS] " RESET << std::endl;
        Intern* newIntern = new Intern ();
        AForm* A;
        AForm* B;
        AForm* C;
        AForm* D;
        A = newIntern->makeForm("ShrubberyCreationForm", "Garden");
        B = newIntern->makeForm("RobotomyRequestForm", "Groar");
        C = newIntern->makeForm("PresidentialPardonForm", "Gerald");
        D = newIntern->makeForm("FakeForm", "Bartolomeo");
        std::cout << *A << std::endl;
        std::cout << *B << std::endl;
        std::cout << *C << std::endl;
        _delete(newIntern);
        _delete(A);
        _delete(B);
        _delete(C);
        _delete(D);
    }
    // {
    //     RobotomyRequestForm* formA = new RobotomyRequestForm("TARGET");
    //     Bureaucrat* Gripsec = new Bureaucrat("Gripsec", 6);
    //     Bureaucrat* Gripsou = new Bureaucrat("Gripsou", 5);
    //     Bureaucrat* Gripbec = new Bureaucrat("Gripbec", 4);
    //     std::cout << WHITE "-------------" RESET << std::endl;
    //     std::cout << "Form |\t" << formA << "\t\t" << *formA << std::endl;
    //     std::cout << "Gripsec |\t" << Gripsec << "\t\t" << *Gripsec << std::endl;
    //     std::cout << "Gripsou |\t" << Gripsou << "\t\t" << *Gripsou << std::endl;
    //     std::cout << "Gripbec |\t" << Gripbec << "\t\t" << *Gripbec << std::endl;
    //     std::cout << WHITE "-------------" RESET << std::endl;
    //     Gripsec->signForm(*formA);
    //     Gripsou->signForm(*formA);
    //     Gripbec->signForm(*formA);
    //     std::cout << WHITE "-------------" RESET << std::endl;
    //     Gripsec->executeForm(*formA);
    //     Gripsou->executeForm(*formA);
    //     Gripbec->executeForm(*formA);
    //     std::cout << WHITE "-------------" RESET << std::endl;
    //     _delete(formA);
    //     _delete(Gripsec);
    //     _delete(Gripsou);
    //     _delete(Gripbec);
    // }
    // {
    //     ShrubberyCreationForm* Shrub = new ShrubberyCreationForm("Jardin");
    //     Bureaucrat* Gripsec = new Bureaucrat("Gripsec", 146);
    //     Bureaucrat* Gripsou = new Bureaucrat("Gripsou", 144);
    //     Bureaucrat* Gripbec = new Bureaucrat("Gripbec", 137);
    //     std::cout << WHITE "-------------" RESET << std::endl;
    //     std::cout << "Shrub |\t" << Shrub << "\t\t" << *Shrub << std::endl;
    //     std::cout << "Gripsec |\t" << Gripsec << "\t\t" << *Gripsec << std::endl;
    //     std::cout << "Gripsou |\t" << Gripsou << "\t\t" << *Gripsou << std::endl;
    //     std::cout << "Gripbec |\t" << Gripbec << "\t\t" << *Gripbec << std::endl;
    //     std::cout << WHITE "-------------" RESET << std::endl;
    //     Gripsec->signForm(*Shrub);
    //     Gripsou->signForm(*Shrub);
    //     Gripbec->signForm(*Shrub);
    //     std::cout << WHITE "-------------" RESET << std::endl;
    //     Gripsec->executeForm(*Shrub);
    //     Gripsou->executeForm(*Shrub);
    //     Gripbec->executeForm(*Shrub);
    //     std::cout << WHITE "-------------" RESET << std::endl;
    //     _delete(Shrub);
    //     _delete(Gripsec);
    //     _delete(Gripsou);
    //     _delete(Gripbec);

    // }
    // {
    //     std::cout << BOLDWHITE "------------- [SHRUBBERY FORM] [TEST CLASS] " RESET << std::endl;

        
    //     ShrubberyCreationForm* Shrub = new ShrubberyCreationForm();
    //     ShrubberyCreationForm* Shrob = new ShrubberyCreationForm("Jardin");
    //     ShrubberyCreationForm* Shrab = new ShrubberyCreationForm(*Shrub);
    //     std::cout << WHITE "-------------" RESET << std::endl;

    //     std::cout << "Shrub |\t" << Shrub << "\t\t" << *Shrub << std::endl;
    //     std::cout << "Shrob |\t" << Shrob << "\t\t" << *Shrob << std::endl;
    //     std::cout << "Shrab |\t" << Shrab << "\t\t" << *Shrab << std::endl;
    //     std::cout << WHITE "-------------" RESET << std::endl;

    //     *Shrub = *Shrob;
    //     std::cout << WHITE "-------------" RESET << std::endl;

    //     std::cout << "Shrub |\t" << Shrub << "\t\t" << *Shrub << std::endl;
    //     std::cout << "Shrob |\t" << Shrob << "\t\t" << *Shrob << std::endl;
    //     std::cout << "Shrab |\t" << Shrab << "\t\t" << *Shrab << std::endl;
    //     std::cout << WHITE "-------------" RESET << std::endl;

    //     _delete(Shrub);
    //     _delete(Shrob);
    //     _delete(Shrab);

    // }
    // {
    //     std::cout << BOLDWHITE "------------- [FUUNCTION] [TEST] " RESET << std::endl;
    //     Bureaucrat* Gripsec = new Bureaucrat("Gripsec", 0);
    //     Bureaucrat* Gripsou = new Bureaucrat("Gripsou", 151);
    //     Bureaucrat* Gripbec = new Bureaucrat("Gripbec", 70);
    //     AForm* A = new AForm("A", 70, 170);
    //     A->beSigned(*Gripsec);
    //     A->beSigned(*Gripsou);
    //     A->beSigned(*Gripbec);
    // }
    // {
    //     std::cout << BOLDWHITE "------------- [FORM] [TEST CLASS] " RESET << std::endl;
    //     AForm* A = new AForm();
    //     std::cout << WHITE "-------------" RESET << std::endl;
    //     AForm* B = new AForm("B", 0, 170);
    //     std::cout << WHITE "-------------" RESET << std::endl;
    //     AForm* C = new AForm(*B);
    //     std::cout << WHITE "-------------" RESET << std::endl;

    //     std::cout << "A |\t" << A << "\t\t" << *A << std::endl;
    //     std::cout << "B |\t" << B << "\t\t" << *B << std::endl;
    //     std::cout << "C |\t" << C << "\t\t" << *C << std::endl;

    //     *A = *B;

    //     std::cout << "A |\t" << A << "\t\t" << *A << std::endl;
    //     std::cout << "B |\t" << B << "\t\t" << *B << std::endl;
    //     std::cout << "C |\t" << C << "\t\t" << *C << std::endl;

    //     _delete(A);
    //     _delete(B);
    //     _delete(C);
    // }
    // {
    //     std::cout << BOLDWHITE "------------- [BUREAUCRAT] [TEST CLASS] " RESET << std::endl;
    //     // Bureaucrat* Gripbec = new Bureaucrat();
    //     Bureaucrat* Gripbec = new Bureaucrat("Gripbec", 151);
    //     Bureaucrat* Gripsec = new Bureaucrat("Gripsec", 2);
    //     Bureaucrat* Gripsou = new Bureaucrat("Gripsou", 0);
    //     // Bureaucrat* Gripsou = new Bureaucrat(*Gripsec);

    //     std::cout << "Gripbec | " << Gripbec << *Gripbec<< std::endl;
    //     std::cout << "Gripsec | " << Gripsec << *Gripsec<< std::endl;
    //     std::cout << "Gripsou | " << Gripsou << *Gripsou<< std::endl;

    //     *Gripbec = *Gripsec;

    //     std::cout << "Gripbec | " << Gripbec << *Gripbec<< std::endl;
    //     std::cout << "Gripsec | " << Gripsec << *Gripsec<< std::endl;
    //     std::cout << "Gripsou | " << Gripsou << *Gripsou<< std::endl;

    //     Gripsec->incrGrade();
    //     Gripsec->incrGrade();
    //     Gripsec->incrGrade();

    //     Gripbec->decrGrade();
    //     Gripbec->decrGrade();
    //     Gripbec->decrGrade();

    //     std::cout << "Gripbec | " << Gripbec << *Gripbec<< std::endl;
    //     std::cout << "Gripsec | " << Gripsec << *Gripsec<< std::endl;
    //     std::cout << "Gripsou | " << Gripsou << *Gripsou<< std::endl;

    //     _delete(Gripbec);
    //     _delete(Gripsec);
    //     _delete(Gripsou);
    // }
    return 0;
}