#ifndef BASE_H
#define BASE_H

# include <iostream>
# include <string>

class Base
{
    public:
        Base(int n);
        Base();
        Base(Base & cpy);
        ~Base();

        int     getN() const;
        void    setN(int n);
        
        Base&	operator=(Base & rhs);
        Base&	operator+=(Base & rhs);
        Base&	operator+=(int rhs);

		bool	operator==(Base const & rhs) const;
		bool	operator!=(Base const & rhs) const;
		bool	operator>(Base const & rhs) const;
		bool	operator<(Base const & rhs) const;
		bool	operator>=(Base const & rhs) const;
		bool	operator<=(Base const & rhs) const;

    private:
        int     _n;
};

std::ostream&	operator<<(std::ostream& stream, const Base & obj);

#endif