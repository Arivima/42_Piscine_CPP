# include <iostream>
# include <string>

# include "Data.hpp"

uintptr_t   serialize(Data* ptr);
Data*       deserialize(uintptr_t raw);

int main ()
{
    Data        data = {"HELLO", 1};
    uintptr_t   dp = 0;
    Data*       datap = 0;

    std::cout << "INIT"<< std::endl;
    std::cout << "d\t: " << &data << data << std::endl;
    std::cout << "dp\t: " << dp << std::endl;
    std::cout << "datap\t: " << datap << std::endl;
    std::cout << "SERIALIZE"<< std::endl;
    dp = serialize(&data);
    std::cout << "d\t: " << &data << data << std::endl;
    std::cout << "dp\t: " << dp << std::endl;
    std::cout << "datap\t: " << datap << std::endl;

    std::cout << "DESERIALIZE"<< std::endl;
    datap = deserialize(dp);
    std::cout << "d\t: " << &data << data << std::endl;
    std::cout << "dp\t: " << dp << std::endl;
    std::cout << "datap\t: " << datap << *datap << std::endl;


    return 0;
}

uintptr_t   serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data*       deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}

std::ostream&   operator<<(std::ostream& stream, const Data& obj)
{
    std::cout << "|" << obj.name << ": " << obj.type << "|";
    return stream;
}