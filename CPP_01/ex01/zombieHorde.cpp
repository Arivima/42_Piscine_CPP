# include "ex01.hpp"

Zombie*     ftZombieHorde(int N, std::string name)
{
    Zombie  *myzombiehorde;
    
    myzombiehorde = new Zombie[N];

    for (int i = 0; i < N; i++)
        myzombiehorde[i].ftSetName(name + '_' + std::to_string(i));
  
    return myzombiehorde;
}
