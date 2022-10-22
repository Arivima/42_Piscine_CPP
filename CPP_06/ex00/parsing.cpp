# include "Exceptions.hpp"
enum ret_type { ret_char, ret_int, ret_float, ret_double };

bool    ftIsFloatDigit(std::string s)
{
    bool flag_f = 0;
    bool flag_d = 0;
    for (int i = 0; i < static_cast<int>(s.size()); i++)
    {
        if (std::isdigit(s.at(i)) == 0 && s.at(i) != 'f' && s.at(i) != '.' && s.at(i) != '-') 
            return false; // cannot have character that are not digit, not 'f' or not '.'
        if (s.at(i) == 'f' && flag_f == 0)
            flag_f = 1;
        else if (s.at(i) == '.' && flag_d == 0)
            flag_d = 1;
        else if (s.at(i) == '.' && flag_d == 1) 
            return false; // cannot have more than one '.'
        else if (s.at(i) == '-' && i != 0)
            return false; // cannot have '-' after first character
        else if (flag_f == 1)
            return false; // cannot have character after 'f'
    } 
    return true;
}

bool    ftIsDoubleDigit(std::string s)
{
    bool flag_d = 0;
    for (int i = 0; i < static_cast<int>(s.size()); i++)
    {
        if (std::isdigit(s.at(i)) == 0 && s.at(i) != '.' && s.at(i) != '-') 
            return false; // cannot have character that are not digit, or not '.'
        else if (s.at(i) == '.' && flag_d == 0)
            flag_d = 1;
        else if (s.at(i) == '.' && flag_d == 1) 
            return false; // cannot have more than one '.'
        else if (s.at(i) == '-' && i != 0)
            return false; // cannot have '-' after first character
        } 
    return true;
}

bool    ftIsDigit(std::string s)
{
    for (int i = 0; i < static_cast<int>(s.size()); i++)
    {
        if (std::isdigit(s.at(i)) == 0 && s.at(i) != '-') 
            return false; // cannot have character that are not digit
        else if (s.at(i) == '-' && i != 0)
            return false; // cannot have '-' after first character
    } 
    return true;
}

int parsing(std::string input) // identifying type of arg
{
    // check is char
    if (input.size() == 1 && std::isdigit(static_cast<char>(input.front())) == false) 
    {
        if (std::isprint(static_cast<char>(input.front()))) // check is print
            return ret_char;
        else
            throw Exceptions::CharNotPrintableException();
    }
    // check is inf/nan float
    else if (input.compare("-inff") == 0 || input.compare("+inff") == 0 || input.compare("nanf") == 0)
        return ret_float;
    // check is inf/nan double
    else if (input.compare("-inf") == 0 || input.compare("+inf") == 0 || input.compare("nan") == 0)
        return ret_double;
    // check is float
    else if (input.find("f") != std::string::npos) // must have a 'f'
    {
        if (input.find(".") == std::string::npos) // must have a '.'
            throw Exceptions::WrongInputException();
        if (ftIsFloatDigit(input) == false)
            throw Exceptions::WrongInputException();
        try
        {
            std::stof(input); // check max min float
        }
        catch (std::exception& e)
        {
            throw Exceptions::WrongInputFloatException();
        }
        return ret_float;
    } 
    // check is double
    else if (input.find(".") != std::string::npos) // must have a '.'
    {
        if (ftIsDoubleDigit(input) == false)
            throw Exceptions::WrongInputException();
        try
        {
            std::stod(input); // check max min double
        }
        catch (std::exception& e)
        {
            throw Exceptions::WrongInputDoubleException();
        }
        return ret_double;
    }
    // check is int
    else if (ftIsDigit(input) == true)
    {
        try
        {
            std::stoi(input); // check max min int
        }
        catch (std::exception& e)
        {
            throw Exceptions::WrongInputIntException();
        }
        return ret_int;
    }            
    else
        throw Exceptions::WrongInputException();
    return 0; 
}
