#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include "header.hpp"

# include <iostream>
# include <stack>
# include <algorithm>
# include <ctime>
# include <cstdlib>

// std::stack
// top()
// empty()
// size()
// push()
// pop()

template <typename T >
class MutantStack : public std::stack<T>
{
public:
    // constructors, destructors
                    MutantStack     (void);
                    MutantStack     (const MutantStack & cpy);
                    ~MutantStack    (void);

    // operators
    MutantStack &   operator=       (const MutantStack& cpy);
    // iterators
    typedef typename std::deque<T>::iterator	iterator;
    iterator        begin           (void);
    iterator        end           (void);

};

template <typename T>
std::ostream&       operator<<( std::ostream &stream, const MutantStack<T> &obj );

# include "MutantStack.tpp"

#endif

