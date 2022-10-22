# include "prog.class.hpp"

            Prog::Prog(std::string name) : errFlag(0), errMsg(""), status(EXIT_SUCCESS), name(name)
{
    return;
}

            Prog::~Prog(void) 
{
    return;
}

void Prog::Enter()
{
   
    std::cout << CYAN"---------" RESET << std::endl;
    std::cout << BOLDCYAN"Welcome to [" << this->name << "]." RESET << std::endl;
    std::cout << CYAN"---------" RESET << std::endl; 
}

void Prog::WrongInput()
{
    std::cout << RED"Please launch [" + this->name + "] with : "<< std::endl;
    std::cout << "- Either one command [DEBUG], [INFO], [WARNING], or [ERROR]." << std::endl;
    std::cout << "- Either one positive integer parameter, > 0, being the number of times Harl should complain." RESET << std::endl;
    this->SetError("Wrong input");
    return;
}

int Prog::SetError(std::string errMsg)
{
    this->errFlag += 1;
    this->errMsg.assign(errMsg);
    this->status = EXIT_FAILURE;
    return -1;
}

void Prog::PrintifError(void)
{
    if (this->errFlag == 0)
        std::cout << GREEN "---------" << std::endl << "Program executed successfully." RESET << std::endl;
    else
        std::cerr << RED "---------" << std::endl << "Error." << std::endl << this->errMsg << "." RESET << std::endl;
    return;
}

int Prog::Exit(void)
{
    PrintifError();

    std::cout << CYAN"---------" RESET << std::endl;
    std::cout << CYAN"Exiting [" << this->name << "]." RESET << std::endl;
    std::cout << CYAN"Status : " << this->status << "." RESET << std::endl;
    std::cout << BOLDCYAN"Bye Bye." RESET << std::endl;
    std::cout << CYAN"---------" RESET << std::endl;
    return this->status;
}

// UTILS
int    Prog::ftStoi(std:: string str)
{
    int nb(0);
    try
    {
        nb = std::stoi(str);
    }
    catch (std::invalid_argument &err)
    {
        this->SetError(err.what());
    }
    catch (std::out_of_range &err)
    {
        this->SetError(err.what());
    }
    return nb;
}