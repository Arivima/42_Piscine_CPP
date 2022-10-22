#ifndef HEADER_H
#define HEADER_H

// header
# include <iostream>
# include <string>
# include <stdexcept>
# include <limits>
# include <iomanip>

bool    ftIsFloatDigit  (std::string s);
bool    ftIsDoubleDigit (std::string s);
bool    ftIsDigit       (std::string s);
int     parsing         (std::string input);
enum    ret_type        { ret_char, ret_int, ret_float, ret_double };

// debug
# define DEBUG          1
# define _delete(ptr)   { delete ptr; ptr = nullptr; if (DEBUG) std::cout << RED "// safely _deleted" RESET << std::endl; }

// colors
# define RESET          "\033[0m"
# define BLACK          "\033[30m"
# define RED            "\033[31m"
# define GREEN          "\033[32m"
# define YELLOW         "\033[33m"
# define BLUE           "\033[34m"
# define MAGENTA        "\033[35m"
# define CYAN           "\033[36m"
# define WHITE          "\033[37m"

# define BOLDBLACK      "\033[1m\033[30m"
# define BOLDRED        "\033[1m\033[31m"
# define BOLDGREEN      "\033[1m\033[32m"
# define BOLDYELLOW     "\033[1m\033[33m"
# define BOLDBLUE       "\033[1m\033[34m"
# define BOLDMAGENTA    "\033[1m\033[35m"
# define BOLDCYAN       "\033[1m\033[36m"
# define BOLDWHITE      "\033[1m\033[37m"

#endif