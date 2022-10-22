#ifndef DATA_H
#define DATA_H

# include <iostream>
# include <string>

// structures
typedef struct s_Data
{
    std::string name;
    int         type;
}               Data;

std::ostream&   operator<<(std::ostream& stream, const Data& obj);

#endif