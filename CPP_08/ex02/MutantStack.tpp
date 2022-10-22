# include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>()
{
    std::cout << GREEN "Default Constructor called" RESET << std::endl;
    return;
}

template <typename T >
MutantStack<T>::MutantStack     (const MutantStack & cpy)
{
    std::cout << GREEN "Copy Constructor called" RESET << std::endl;
    *this = cpy;
    return;
}

template <typename T >
MutantStack<T>::~MutantStack<T>   (void)
{
    std::cout << RED "Destructor called" RESET << std::endl;
    return;
}

template <typename T >
MutantStack<T> &              MutantStack<T>::operator=(const MutantStack<T>& cpy)
{
    // this->~MutantStack();
	// new (this) MutantStack();
    this->c = cpy.c;
    return *this;
}

template <typename T >
std::ostream& operator<<( std::ostream &stream,  MutantStack<T> &obj )
{
    stream <<  MAGENTA "Printing MutantStack | " ;
    stream <<  "size: " << obj.size() <<RESET YELLOW << " " ;
    if (obj.empty () == false)
    {
        for (MutantStack<int>::iterator it = obj.begin(); it != obj.end(); it++)
            stream << "|" << *it;
        stream << "|";
    }
    else
        stream <<  " MutantStack empty";
    stream << RESET << std::endl;
    return stream;
}

template <typename T >
typename MutantStack<T>::iterator        MutantStack<T>::begin(void)
{
    return iterator(this->c.begin());
}

template <typename T >
typename MutantStack<T>::iterator        MutantStack<T>::end(void)
{
    return iterator(this->c.end());
}

