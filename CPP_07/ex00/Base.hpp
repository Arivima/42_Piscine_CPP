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
        
        Base&	operator=(Base & rhs);

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