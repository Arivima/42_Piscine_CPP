# include "template.hpp"
# include "Base.hpp"

# include <iostream>
# include <string>
# include <cmath>

int main( void )
{
    {
        float a[5] = {2.5, 3.6, 4.2, 5.0, 6.9};
        std::cout << "--------------- FLOAT" << std::endl;
        std::cout << "before" << std::endl;
        iter(a, 5, printN<float>);
        std::cout << "---------------" << std::endl;
        std::cout << "after" << std::endl;
        iter(a, 5, incr<float>);
        iter(a, 5, printN<float>);
        std::cout << "---------------" << std::endl;
    }


    {
        int a[5] = {2, 3, 4, 5, 6};
        std::cout << "--------------- INT" << std::endl;
        std::cout << "before" << std::endl;
        iter(a, 5, printN<int>);
        std::cout << "---------------" << std::endl;
        std::cout << "after" << std::endl;
        iter(a, 5, incr<int>);
        iter(a, 5, printN<int>);
        std::cout << "---------------" << std::endl;
    }

    {
        char a[5] = {'a', 'b', 'c', 'd', 'e'};
        std::cout << "--------------- CHAR" << std::endl;
        std::cout << "before" << std::endl;
        iter(a, 5, printN<char>);
        std::cout << "---------------" << std::endl;
        std::cout << "after" << std::endl;
        iter(a, 5, incr<char>);
        iter(a, 5, printN<char>);
        std::cout << "---------------" << std::endl;
    }

    {
        std::string a[5] = {"hello", "hella", "helli", "hellu", "helle"};
        std::cout << "--------------- STRING" << std::endl;
        std::cout << "before" << std::endl;
        iter(a, 5, printN<std::string>);
        std::cout << "---------------" << std::endl;
        std::cout << "after" << std::endl;
        iter(a, 5, addself<std::string>);
        iter(a, 5, printN<std::string>);
        std::cout << "---------------" << std::endl;
    }

    {
        Base * a = new Base[5];
        for (int i = 0; i < 5; i++)
            a[i].setN(i);
        std::cout << "--------------- CLASS BASE" << std::endl;
        std::cout << "before" << std::endl;
        iter(a, 5, printN<Base>);
        std::cout << "---------------" << std::endl;
        std::cout << "after" << std::endl;
        iter(a, 5, incr<Base>);
        iter(a, 5, printN<Base>);
        delete[](a);
        std::cout << "---------------" << std::endl;

    }

    return 0;
}