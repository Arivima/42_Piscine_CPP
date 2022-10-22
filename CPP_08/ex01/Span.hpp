#ifndef SPAN_HPP
# define SPAN_HPP

# include "header.hpp"

# include <iostream>
# include <vector>
# include <algorithm>
# include <ctime>
# include <cstdlib>

# define RAND_RANGE 1000

class Span
{
private:
    typedef std::vector<int>::iterator  iterator;
    const unsigned int                  _N;
    std::vector<int>                    _array;

public:
                        Span        (void);
                        Span        (const Span & cpy);
                        Span        (const unsigned int N);
                        ~Span       (void);

    Span &              operator=   (const Span& cpy);

    const unsigned int& getN        (void)const ;
    const std::vector<int>&   getA        (void)const ;

    void                addNumber   (void);
    void                addNumber   (int i);
    void                addRange    (void);
    void                addRange    (iterator begin, iterator end);
    int                 shortestSpan(void);
    int                 longestSpan (void);
};

std::ostream&	operator<<(std::ostream& stream, Span& obj);

#endif