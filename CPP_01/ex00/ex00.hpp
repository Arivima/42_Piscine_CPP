#ifndef EX00_H
#define EX00_H

# include "zombie.class.hpp"
# include "colors.hpp"

# include <iostream>
# include <string>

// main.cpp
int         ftZombie(void);
int         ftExit(char *name, int status);

//newzombie.cpp
Zombie*     ftNewZombie(std::string name);

//randomChump.cpp
void        ftRandomChump(std::string name);

#endif