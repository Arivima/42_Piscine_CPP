# include "Fixed.class.hpp"
# include <math.h>

int main( void ) 
{
    {
        system("clear");
        // std::cout << "------------- TEST classes overloads " << std::endl;
        // std::cout << "a : ";
        // Fixed a;
        // std::cout << "b : ";
        // Fixed b(a);
        // std::cout << "c : ";
        // Fixed c(10);
        // std::cout << "d : ";
        // Fixed d(10.52f);
        // std::cout << "e : ";
        // Fixed const e( Fixed( 35.05f ));

        // std::cout << ">Fixed = Int\n";
        // a = 42;
        // std::cout << ">Fixed = Float\n";
        // a = 42.42f;
        // std::cout << ">Fixed = Fixed\n";
        // d = a;

        // std::cout << "------------- TEST arithm operations " << std::endl;
        // std::cout << ">Fixed = Fixed + Fixed\n";
        // a = 2 + 3;
        // std::cout << "a : " << a << std::endl;

        // std::cout << ">Fixed = Fixed - Fixed\n";
        // a = 5 - 1;
        // std::cout << "a : " << a << std::endl;

        // std::cout << ">Fixed = Fixed * Fixed\n";
        // a = 2 * 3;
        // std::cout << "a : " << a << std::endl;

        // std::cout << ">Fixed = Fixed / Fixed\n";
        // a = 6 / 2;
        // std::cout << "a : " << a << std::endl;

    //     std::cout << "------------- TEST incrementation " << std::endl;

    //     b = 0;
    //     std::cout << "++b\n";
    //     if (++b == 1)
    //         std::cout << "incremented before evaluation\n";
    //     else if (b == 1)
    //         std::cout << "incremented after evaluation\n";
    //     std::cout << "b : " << b << std::endl;
    //     std::cout << "++b : " << ++b << std::endl;
    //     std::cout << "b : " << b << std::endl;
    //     std::cout << std::endl;

    //     b = 0;
    //     std::cout << "b++\n";
    //     if (b++ == 1)
    //         std::cout << "incremented before evaluation\n";
    //     else if (b == 1)
    //         std::cout << "incremented after evaluation\n";
    //     std::cout << "b : " << b << std::endl;
    //     std::cout << "b++ : " << b++ << std::endl;
    //     std::cout << "b : " << b << std::endl;
    //     std::cout << std::endl;

    // std::cout << "------------- TEST incrementation " << std::endl;

    //     b = 0;
    //     std::cout << "--b\n";
    //     if (--b == 1)
    //         std::cout << "incremented before evaluation\n";
    //     else if (b == 1)
    //         std::cout << "incremented after evaluation\n";
    //     std::cout << "b : " << b << std::endl;
    //     std::cout << "--b : " << --b << std::endl;
    //     std::cout << "b : " << b << std::endl;
    //     std::cout << std::endl;

    //     b = 0;
    //     std::cout << "b--\n";
    //     if (b-- == 1)
    //         std::cout << "incremented before evaluation\n";
    //     else if (b == 1)
    //         std::cout << "incremented after evaluation\n";
    //     std::cout << "b : " << b << std::endl;
    //     std::cout << "b-- : " << b-- << std::endl;
    //     std::cout << "b : " << b << std::endl;
    //     std::cout << std::endl;


    //     std::cout << "------------- TEST i++ " << std::endl;
    //     int i = 0;
    //     std::cout << "++i\n";
    //     if (++i == 1)
    //         std::cout << "incremented before evaluation\n";
    //     else if (i == 1)
    //         std::cout << "incremented after evaluation\n";
    //     std::cout << "i : " << i << std::endl;
    //     std::cout << "++i : " << ++i << std::endl;
    //     std::cout << "i : " << i << std::endl;
    //     std::cout << std::endl;

    //     i = 0;
    //     std::cout << "i++\n";
    //     if (i++ == 1)
    //         std::cout << "incremented before evaluation\n";
    //     else if (i == 1)
    //         std::cout << "incremented after evaluation\n";
    //     std::cout << "i : " << i << std::endl;
    //     std::cout << "i++ : " << i++ << std::endl;
    //     std::cout << "i : " << i << std::endl;
    //     std::cout << std::endl;

        // std::cout << "------------- TEST comparaisons " << std::endl;
        // a = 10.12f;
        // b = 11.12f;
        // std::cout << "a : " << a << std::endl;
        // std::cout << "b : " << b << std::endl;
        // std::cout << "a < b : " << (a < b) << std::endl;
        // std::cout << "a > b : " << (a > b) << std::endl;
        // std::cout << "a <= b : " << (a <= b) << std::endl;
        // std::cout << "a >= b : " << (a >= b) << std::endl;
        // std::cout << std::endl;

        // std::cout << "------------- TEST min " << std::endl;
        // a = 10.12f;
        // b = 11.12f;
        // std::cout << "a : " << a << std::endl;
        // std::cout << "b : " << b << std::endl;
        // std::cout << Fixed::min( a, b ) << std::endl;
        // std::cout << Fixed::max( a, b ) << std::endl;
        // std::cout << std::endl;
    }

    // {
    //     std::cout << "------------- TEST MAIN SUBJECT " << std::endl;
    //     Fixed a;
    //     std::cout << "\n\nFixed const b( Fixed( 5.05f ) * Fixed( 2 ) );: " << std::endl;
    //     Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    //     std::cout << "\na: \n" <<  a << std::endl;
    //     std::cout << "\na: \n" << ++a << std::endl;
    //     std::cout << "\na: \n" << a << std::endl;
    //     std::cout << "\na: \n" << a++ << std::endl;
    //     std::cout << "\na: \n" << a << std::endl;
    //     std::cout << "\nb: \n" << b << std::endl;
    //     std::cout << "\nmax: \n" << Fixed::max( a, b ) << std::endl;
    // }
    {
        std::cout << "------------- TEST MAIN SUBJECT " << std::endl;
        Fixed a;
        Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
        std::cout << a << std::endl;
        std::cout << ++a << std::endl;
        std::cout << a << std::endl;
        std::cout << a++ << std::endl;
        std::cout << a << std::endl;
        std::cout << b << std::endl;
        std::cout << Fixed::max( a, b ) << std::endl;
    }

    return 0;

}
