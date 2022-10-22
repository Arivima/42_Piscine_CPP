# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

# include <iostream>
# include <string>

# define TEST_NB 10

Base *  generate    (void);
void    identify    (Base* p);
void    identify    (Base& p);


int main ()
{
    Base *  ptr[TEST_NB];
    
    for (int i = 0; i < TEST_NB; i++)
    {
        std::cout << "Test " << i << "|";
        ptr[i] = generate();
        std::cout << "|";
        identify(ptr[i]);
        std::cout << "|";
        identify(*ptr[i]);
        std::cout << "|" << std::endl;

    }
    return 0;
}
void    identify    (Base& p)
{
    std::cout << " (identify ref) ";
    try
    {
        A & ptra = dynamic_cast<A&>(p);
        std::cout << "is A (" << &ptra << ")";
    }
    catch (std::bad_cast &bc)
    {
    }
    try
    {
        B & ptrb = dynamic_cast<B&>(p);
        std::cout << "is B (" << &ptrb << ")";
    }
    catch (std::bad_cast &bc)
    {
    }
    try
    {
        C & ptrc = dynamic_cast<C&>(p);
        std::cout << "is C (" << &ptrc << ")";
    }
    catch (std::bad_cast &bc)
    {
    }
    return;
}

void    identify    (Base* p)
{
    std::cout << " (identify ptr) ";
    if (dynamic_cast<A*>(p) != NULL)
        std::cout << "is A";
    else if (dynamic_cast<B*>(p) != NULL)
        std::cout << "is B";
    else if (dynamic_cast<C*>(p) != NULL)
        std::cout << "is C";
    else
        std::cout << "is unknown type";
    return;
}

Base*   generate(void)
{
    std::cout << " (generate) ";
    Base *  inst = 0;
    switch (std::rand() % 3)
    {
    case 0:
        inst = new A();
        std::cout << "A: " << inst;
        break;
    case 1:
        inst = new B();
        std::cout << "B: " << inst;
        break;
    case 2:
        inst = new C();
        std::cout << "C: " << inst;
        break;    
    default:
        break;
    }
    return (inst);
}
