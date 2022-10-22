#ifndef HEADER_H
#define HEADER_H

// header
# include <iostream>
# include <stdexcept>
# include <deque>
# include <vector>
# include <list>
# include <algorithm>

// debug
# define DEBUG          1
# define _delete(ptr)   { delete ptr; ptr = nullptr; if (DEBUG) std::cout << RED "// safely _deleted" RESET << std::endl; }

// utils


// colors
# define RESET          "\033[0m"
# define BOLD           "\033[1m"
# define FAINT          "\033[2m"
# define UNDERLINED     "\033[4m"
# define BLINK          "\033[5m"

// Regular
# define BLACK          "\033[30m"
# define RED            "\033[31m"
# define GREEN          "\033[32m"
# define YELLOW         "\033[33m"
# define BLUE           "\033[34m"
# define MAGENTA        "\033[35m"
# define CYAN           "\033[36m"
# define WHITE          "\033[37m"

// Background
# define BBLACK          "\033[40m"
# define BRED            "\033[41m"
# define BGREEN          "\033[42m"
# define BYELLOW         "\033[43m"
# define BBLUE           "\033[44m"
# define BMAGENTA        "\033[45m"
# define BCYAN           "\033[46m"
# define BWHITE          "\033[47m"

// Bright
# define BRIGHTBLACK          "\033[90m"
# define BRIGHTRED            "\033[91m"
# define BRIGHTGREEN          "\033[92m"
# define BRIGHTYELLOW         "\033[93m"
# define BRIGHTBLUE           "\033[94m"
# define BRIGHTMAGENTA        "\033[95m"
# define BRIGHTCYAN           "\033[96m"
# define BRIGHTWHITE          "\033[97m"

#endif