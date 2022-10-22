# include "header.hpp"
# include "Exceptions.hpp"

bool    flag_char       = 0;
bool    flag_int        = 0;
bool    flag_double     = 0;
bool    flag_float      = 0;

void    printTypes(char A, int B, float C, double D)
{
    std::cout << "----------------" << std::endl;
    if (flag_char == 0) 
    {
        if (std::isprint(A) != 0)
            std::cout << "char: '" << A << "'" << std::endl;
        else
            std::cout << "char: cannot be printed" << std::endl;
    }
    else
        std::cout << "char: conversion impossible" << std::endl;

    if (flag_int == 0) 
        std::cout << "int: " << B << std::endl;
    else
        std::cout << "int: conversion impossible" << std::endl;

    if (flag_float == 0) 
    {
        std::cout << "float: " << C << "f" << std::endl;
    }
    else
        std::cout << "float: conversion impossible" << std::endl;

    if (flag_double == 0) 
    {
        std::cout << "double: " <<  D << std::endl;
    }
    else
        std::cout << "double: conversion impossible" << std::endl;

    std::cout << "----------------" << std::endl;
    return;
}

int main (int ac, char** av)
{
    char    A = '\0';
    int     B = 0;
    float   C = 0.0;
    double  D = 0.0;

    std::cout << std::setprecision(1) << std::fixed;
    try
    {
        if (ac == 2) // Checking num of arg
        {
            // parsing
            switch (parsing(av[1])) // checking validity of input and return identified type
            {
                case ret_char: 
                    A = av[1][0];
                    std::cout << "Arg: " << av[1] << " is char " << A << std::endl;
                    break;
                case ret_int: 
                    B = std::stoi(av[1]);
                    std::cout << "Arg: " << av[1] << " is int " << B << std::endl;
                    break;
                case ret_float: 
                    C = std::stof(av[1]);
                    std::cout << "Arg: " << av[1] << " is float " << C << "f" << std::endl;
                    break;
                case ret_double: 
                    D = std::stod(av[1]);
                    std::cout << "Arg: " << av[1] << " is double " << D << std::endl;
                    break;
                default: 
                    std::cout << "is other " << std::endl;
            }
            // execution
            if (A != '\0')
            {
                B = static_cast<int>(A);
                C = static_cast<float>(A);
                D = static_cast<double>(A);
            }
            else if (B != 0)
            {
                if (B > std::numeric_limits<char>::max() || B < std::numeric_limits<char>::lowest())
                    flag_char = 1;
                else
                    A = static_cast<char>(B);
                C = static_cast<float>(B);
                D = static_cast<double>(B);
            }
            else if (C != 0.0)
            {
                if (C > std::numeric_limits<char>::max() || C < std::numeric_limits<char>::lowest())
                    flag_char = 1;
                else if (((std::string)av[1]).compare("nanf") == 0)
                    flag_char = 1;
                else
                    A = static_cast<char>(C);
                if (C > std::numeric_limits<int>::max() || C < std::numeric_limits<int>::lowest())
                    flag_int = 1;
                else if (((std::string)av[1]).compare("nanf") == 0)
                    flag_int = 1;
                else
                    B = static_cast<int>(C);
                D = static_cast<double>(C);
            }
            else if (D != 0.0)
            {
                if (D > std::numeric_limits<char>::max() || D < std::numeric_limits<char>::lowest())
                    flag_char = 1;
                else if (((std::string)av[1]).compare("nan") == 0)
                    flag_char = 1;
                else
                    A = static_cast<char>(D);
                if (D > std::numeric_limits<int>::max() || D < std::numeric_limits<int>::lowest())
                    flag_int = 1;
                else if (((std::string)av[1]).compare("nan") == 0)
                    flag_int = 1;
                else
                    B = static_cast<int>(D);
                if (D > std::numeric_limits<float>::max() || D < std::numeric_limits<float>::lowest())
                    flag_float = 1;
                else
                    C = static_cast<float>(D);
            }
            printTypes(A, B, C, D);
        }
        else
            throw Exceptions::WrongNbArgException();
    }
	catch (std::exception& e)
    {
        if (ac == 2)
            std::cerr << "Arg:\t" << av[1] << std::endl;
        std::cerr << "Error:\t" << e.what() << std::endl;
        return -1;
    }
    return 0;
}