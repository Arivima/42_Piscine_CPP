# include "colors.hpp"
# include "harl.class.hpp"
# include "prog.class.hpp"

void    ftHarlTest(int nbTest, std::string cmd);

int main(int ac, char **av)
{
    Prog    myprog(av[0]);

    system("clear");
    if (ac == 2)
    {
        std::string arg(av[1]);
        myprog.Enter();
        if (arg == "DEBUG" || arg == "INFO" || arg == "WARNING" || arg == "ERROR")
            ftHarlTest(1, arg);
        else
        {
            int nb(myprog.ftStoi(arg));
            if (myprog.errFlag == 0 && nb > 0)
                ftHarlTest(nb, "ALL");
            else
            {
                myprog.WrongInput();
                return myprog.Exit();;
            }
        }
    }
    else
        myprog.WrongInput();
    return myprog.Exit();;
}


void    ftHarlTest(int nbTest, std::string cmd)
{
    std::cout << BOLDWHITE "Testing  \""+ cmd + "\" command, " << nbTest << " times."  RESET << std::endl;
    Harl myHarl;

    if (cmd == "ALL")
    {
        for (int i = 0; i < nbTest; i++)
        {
            std::cout << i << " | ";
            myHarl.complain(std::to_string(i));
        }
    }
    else
        myHarl.complain(cmd);
    return;
}
