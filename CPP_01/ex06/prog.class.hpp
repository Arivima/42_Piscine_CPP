#ifndef     PROG_CLASS_H
# define    PROG_CLASS_H

# include   "colors.hpp"

# include   <iostream>
# include   <string>

# define    ERR -1

class Prog
{
    public:
                        Prog(std::string name);
                        ~Prog(void);

        int             errFlag;
        std::string     errMsg;
        int             status;
        std::string     name;

        void            Enter();
        void            WrongInput();
        int             SetError(std::string errMsg);
        void            PrintifError(void);
        int             Exit(void);

        int             ftStoi(std:: string str);

};

#endif
