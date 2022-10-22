# include "header.hpp"
# include "Exceptions.hpp"
# include "Base.hpp"
# include "Array.hpp"
# include "Array.template.hpp"

int main( void )
{
    {
        std::cout << "--------------- INT ARRAY" << std::endl;
        Array<int> a;
        std::cout << "A" << std::endl;
        std::cout << a << std::endl;
        Array<int> b(4);
        std::cout << "B" << std::endl;
        std::cout << b << std::endl;
        Array<int> c(b);
        std::cout << "C" << std::endl;
        std::cout << c << std::endl;
        std::cout << "---------------" << std::endl;
        b.setA(3); // int
        a = b;
        std::cout << "A: " << a << std::endl;
        std::cout << "B: "<< b << std::endl;
        std::cout << "C: "<< c << std::endl;
        std::cout << "---------------" << std::endl;
    }
    // {
    //     std::cout << "--------------- INT CLASS" << std::endl;
    //     Array<Base> a(5);
    //     std::cout << "A" << std::endl;
    //     std::cout << a << std::endl;
    //     Array<Base> b(10);
    //     std::cout << "B" << std::endl;
    //     std::cout << b << std::endl;
    //     std::cout << "---------------" << std::endl;
    //     a = b;
    //     std::cout << a << std::endl;
    //     std::cout << b << std::endl;
    //     std::cout << "---------------" << std::endl;
    // }
    // {
    //     int * a = new int();
    //     std::cout << *a;
    //     delete a;
    // }
    return 0;
}