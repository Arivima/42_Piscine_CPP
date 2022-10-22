#ifndef SED_CLASS_H
# define SED_CLASS_H

# include <iostream>
# include <string>
# include <fstream> 
# include "colors.hpp"

# define ERR   1

class Sed
{
    public:
                            Sed(void);
                            ~Sed(void);

        int                 ftSed(std::string const fileName, std::string const s1, std::string const s2);

    private:
        std::string         buff;
        std::size_t         flag;
        std::fstream        fileIn, fileOut;

        bool                ftError(std::string errMsg);
        void                ftGetBuff(std::string const s1 , std::string const s2);
        void                ftReplaceBuff(std::string const s1 , std::string const s2);
};

#endif
