# include "Bureaucrat.hpp"

// basics: default, copy, string, destructor, assignment operator, outstream operator
// functions

int main( void ) 
{
    std::cout << BOLDWHITE "------------- STARTING TEST CPP05_EX00 " RESET << std::endl;
    {
        std::cout << BOLDWHITE "------------- [BUREAUCRAT] [TEST CLASS] " RESET << std::endl;
        // Bureaucrat* Gripbec = new Bureaucrat();
        Bureaucrat* Gripbec = new Bureaucrat("Gripbec", 149);
        Bureaucrat* Gripsec = new Bureaucrat("Gripsec", 2);
        Bureaucrat* Gripsou = new Bureaucrat("Gripsou", 0);
        // Bureaucrat* Gripsou = new Bureaucrat(*Gripsec);

        std::cout << "Gripbec | " << Gripbec << *Gripbec<< std::endl;
        std::cout << "Gripsec | " << Gripsec << *Gripsec<< std::endl;
        std::cout << "Gripsou | " << Gripsou << *Gripsou<< std::endl;

        *Gripbec = *Gripsec;

        std::cout << "Gripbec | " << Gripbec << *Gripbec<< std::endl;
        std::cout << "Gripsec | " << Gripsec << *Gripsec<< std::endl;
        std::cout << "Gripsou | " << Gripsou << *Gripsou<< std::endl;

        Gripsec->incrGrade();
        Gripsec->incrGrade();
        Gripsec->incrGrade();

        Gripbec->decrGrade();
        Gripbec->decrGrade();
        Gripbec->decrGrade();

        std::cout << "Gripbec | " << Gripbec << *Gripbec<< std::endl;
        std::cout << "Gripsec | " << Gripsec << *Gripsec<< std::endl;
        std::cout << "Gripsou | " << Gripsou << *Gripsou<< std::endl;

        _delete(Gripbec);
        _delete(Gripsec);
        _delete(Gripsou);
    }
    return 0;
}