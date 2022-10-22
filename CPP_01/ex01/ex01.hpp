#ifndef EX01_H
#define EX01_H

# include "zombie.class.hpp"
# include "colors.hpp"

# include <iostream>
# include <string>

// main.cpp
int         ftZombie(int N, std::string name);
int         ftExit(char *name, int status);
bool        ftIsStrDigit(std::string str);

//zombieHorde.cpp
Zombie*     ftZombieHorde(int N, std::string name);

#endif