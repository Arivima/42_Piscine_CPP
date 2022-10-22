# include "sed.class.hpp"

// constructor
            Sed::Sed(void) : buff(), flag(0), fileIn(), fileOut()
{
    std::cout <<  GREEN "[Constructor]" RESET  <<  std::endl;
    return;
}

// destructor
            Sed::~Sed(void) 
{
    std::cout <<  RED "[Destructor]" RESET  <<  std::endl;
    return;
}

bool        Sed::ftError(std::string errMsg)
{
    std::cout << RED "Error." << std::endl << errMsg << "." RESET << std::endl;
    return ERR;
}

void         Sed::ftReplaceBuff(std::string const s1 , std::string const s2)
{
    std::size_t     found   (this->buff.find(s1));
    int             i = 0;
    
    while (found != std::string::npos)
    {
        // std::cout << this->buff.substr(0, found);                        
        // std::cout << RED << this->buff.substr(found, s1.size()) << "(" << found << ")" RESET;                        
        // std::cout << this->buff.substr(found + s1.size(), this->buff.size()) << std::endl;                        
        this->flag += 1;
        i += found + s1.size();
        this->buff.erase(found, s1.size());
        this->buff.insert(found, s2);
        // std::cout << BLUE << this->buff << RESET << std::endl;                        
        found = this->buff.find(s1, i);
    }
    return;
}

void    Sed::ftGetBuff(std::string const s1 , std::string const s2)
{
    while (this->fileIn.eof() == false)
    {
        getline(this->fileIn, this->buff, '\n');
        ftReplaceBuff(s1, s2);
        this->fileOut << this->buff << std::endl;                        
    }
    if (this->flag == 0)
        std::cout << "!Fyi, no match for remplacement identified"<< std::endl;                        
    return;
}

int         Sed::ftSed(std::string const fileName, std::string const s1, std::string const s2)
{
    {
        this->fileIn.open (fileName, std::fstream::in);
        if (this->fileIn.is_open() == true)
        {
            this->fileOut.open (fileName + ".replace", std::fstream::out | std::fstream::trunc);
            if (this->fileOut.is_open() == true)
            {
                this->ftGetBuff(s1, s2);
                this->fileOut.close();
                this->fileIn.close();
            }
            else
            {
                this->fileIn.close();
                return (this->ftError("Open fileOut"));
            }         
        }
        else
            return (this->ftError("Open fileIn"));
    }
    return 0;
}
