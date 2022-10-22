# include "colors.hpp"
# include "harl.class.hpp"
# include "prog.class.hpp"

int main(int ac, char **av)
{
    Prog    myprog(av[0]);

    system("clear");
    myprog.Enter();
    if (ac == 2)
    {
        std::string arg(av[1]);
        if (arg == "DEBUG" || arg == "INFO" || arg == "WARNING" || arg == "ERROR")
        {
            Harl myHarl;
            myHarl.complain(arg);
        }
        else
            myprog.WrongInput();
    }
    else
        myprog.WrongInput();
    return myprog.Exit();;
}
