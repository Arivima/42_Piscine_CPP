# include "Base.hpp"

        Base::Base  ()          :_n(std::rand() %10)              {}
        Base::Base  (int n)     : _n(n)             {}
        Base::Base  (Base & cpy): _n(cpy.getN())    {*this = cpy;}
        Base::~Base ()                              {}

int     Base::getN  () const                        {return this->_n;}
void    Base::setN  (int n)                         {this->_n = n;}

Base&	Base::operator=(Base & rhs)                 {_n = rhs.getN();return *this;}
const Base&	Base::operator=(const Base & rhs)       {_n = rhs.getN();return *this;}
Base&	Base::operator+=(Base & rhs)                {_n = _n + rhs.getN();return *this;}
Base&	Base::operator+=(int rhs)                   {_n = _n + rhs;return *this;}

bool	Base::operator==(Base const & rhs) const    {return (this->_n == rhs.getN());}
bool	Base::operator!=(Base const & rhs) const    {return (this->_n != rhs.getN());}
bool	Base::operator>(Base const & rhs) const     {return (this->_n > rhs.getN());}
bool	Base::operator<(Base const & rhs) const     {return (this->_n < rhs.getN());}
bool	Base::operator>=(Base const & rhs) const    {return (this->_n >= rhs.getN());}
bool	Base::operator<=(Base const & rhs) const    {return (this->_n <= rhs.getN());}

std::ostream&	operator<<(std::ostream& stream, const Base & obj)
{
    stream << obj.getN();
    return stream;
}
