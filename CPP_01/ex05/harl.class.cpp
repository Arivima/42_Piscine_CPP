# include "harl.class.hpp"

const Harl::t_harl_struct	Harl::Harlarray[4] = {
    {"DEBUG", &Harl::_debug},
    {"INFO", &Harl::_info},
    {"WARNING", &Harl::_warning},
    {"ERROR", &Harl::_error}
};

            Harl::Harl(void)
{
    // std::cout <<  GREEN "[Harl Constructor]" RESET  <<  std::endl;
    return;
}

            Harl::~Harl(void) 
{
    // std::cout <<  RED "[Harl Destructor ]" RESET  <<  std::endl;
    return;
}

int         Harl::_ftStoi(std:: string str)
{
    int nb(0);
    try
    {
        nb = std::stoi(str);
    }
    catch (std::invalid_argument &err)
    {
        std::cerr << err.what() << std::endl;
        return -1;
    }
    catch (std::out_of_range &err)
    {
        std::cerr << err.what() << std::endl;
        return -1;
    }
    return nb;
}

void        Harl::complain(std::string level)
{
    if (level.compare("DEBUG") == 0 || level.compare("INFO") == 0 \
    || level.compare("WARNING") == 0 || level.compare("ERROR") == 0)
    {
        for (int i = 0; i < 4; i++)
        {
            if (level.compare(Harl::Harlarray[i].name) == 0)
                (this->*(Harlarray[i].ptr))();
        }
    }
    else
    {
        int     lvl(this->_ftStoi(level));
        if (lvl == -1)
            return;
        switch (lvl % 4)
            {
                case eDebug:
                    this->_debug();
                    break;
                case eInfo:
                    this->_info();
                    break;
                case eWarning:
                    this->_warning();
                    break;
                case eError:
                    this->_error();
                    break;
                default:
                    break;
            }
    }
    return;
}

void        Harl::_debug(void)
{
    std::cout << YELLOW "1_debug: " << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" RESET << std::endl;
    return;
}

void        Harl::_info(void)
{
    std::cout << MAGENTA "2_info: " << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" RESET << std::endl;
    return;
}

void        Harl::_warning(void)
{
    std::cout << GREEN "3_warning: " << "I think I deserve to have some extra bacon for free. I've been coming foryears whereas you started working here since last month." RESET << std::endl;
    return;
}

void        Harl::_error(void)
{
    std::cout << CYAN "4_error: " << "This is unacceptable! I want to speak to the manager now." RESET << std::endl;
    return;
}
