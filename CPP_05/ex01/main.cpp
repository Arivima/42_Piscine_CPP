# include "Bureaucrat.hpp"
# include "Form.hpp"

// basics: default, copy, string, destructor, assignment operator, outstream operator
// functions

int main( void ) 
{
    std::cout << BOLDWHITE "------------- STARTING TEST CPP05_EX00 " RESET << std::endl;
    {
        std::cout << BOLDWHITE "------------- [FUUNCTION] [TEST] " RESET << std::endl;
        Bureaucrat* Gripsec = new Bureaucrat("Gripsec", 0);
        Bureaucrat* Gripsou = new Bureaucrat("Gripsou", 151);
        Bureaucrat* Gripbec = new Bureaucrat("Gripbec", 70);
        Form* A = new Form("A", 70, 170);
        A->beSigned(*Gripsec);
        A->beSigned(*Gripsou);
        A->beSigned(*Gripbec);
    }
    // {
    //     std::cout << BOLDWHITE "------------- [FORM] [TEST CLASS] " RESET << std::endl;
    //     Form* A = new Form();
    //     std::cout << WHITE "-------------" RESET << std::endl;
    //     Form* B = new Form("B", 0, 170);
    //     std::cout << WHITE "-------------" RESET << std::endl;
    //     Form* C = new Form(*B);
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