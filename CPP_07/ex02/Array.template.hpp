#ifndef ARRAY_TEMPLATE_HPP
# define ARRAY_TEMPLATE_HPP

# include "Array.hpp"

template <typename T>
Array<T>::Array() : _array(nullptr), _size(0), _type(typeid(T).name())
{
	std::cout << GREEN << "Array Default Constructor called" << RESET << std::endl;
    return;
}

template <typename T>
Array<T>::Array(unsigned int size) : _array(new T[size]()), _size(size), _type(typeid(T).name())
{
    std::cout << GREEN << "Array Fields Constructor called" << RESET << std::endl;
    return;
}

template <typename T>
Array<T>::Array(Array & cpy) : _array(nullptr), _size(cpy.size()), _type(cpy.getT())
{
    std::cout << GREEN << "Array Copy Constructor called" << RESET << std::endl;
    *this = cpy;
    return;
}

template <typename T>
Array<T>::~Array()
{
    std::cout << RED << "Array Default Destructor called" << RESET << std::endl;
	delete[] this->_array;
	this->_array = nullptr;
	this->_size = 0;
	this->_type.clear();
	std::cout << RED << "// safely destroyed" << RESET << std::endl;
    return;
}

template <typename T>
T*              Array<T>::getA() const
{
    return this->_array;
}

template <typename T>
int             Array<T>::size() const
{
    return this->_size;
}

template <typename T>
std::string     Array<T>::getT() const
{
    return this->_type;
}

template <typename T>
void            Array<T>::setA(const T& val)
{
    for (int i = 0; i < this->size(); i++)
        this->_array[i] = val;
    return;
}

template <typename T>
Array<T>&          Array<T>::operator=(Array & rhs)
{
	delete[] this->_array;
	this->_array = nullptr;
	this->_size = 0;
	this->_type.clear();

	this->_array = new T[rhs.size()]();
	for (int i = 0; i < rhs.size(); i++)
        this->_array[i] = rhs._array[i];
    this->_size = rhs.size();
    this->_type.assign(rhs.getT());
    return *this;
}

template <typename T>
T&          Array<T>::operator[](int i)
{
    if (i >= 0 && i < this->size())
    {
		return (this->_array[i]);
    }
    else
        throw OutOfRange();
}

template <typename T>
const T&          Array<T>::operator[](int i) const
{
    if (i >= 0 && i < this->size())
    {
		return (this->_array[i]);
    }
    else
        throw OutOfRange();
}

template <typename T>
std::ostream&	operator<<(std::ostream& stream, const Array<T> & obj)
{
    stream << "Printing Array (" << &obj << ") of size (" << obj.size() << ") and type (" << obj.getT() << ")." << std::endl;
    for (int i = 0; i < obj.size() ; i++)
    {
        try
        {
            stream << "Element #" << i << "| (" << &obj[i] << ") |" << " (" << obj[i] << ")" << std::endl;
        }
        catch (std::exception& e)
        {
            std::cout << "Error:" << e.what() << std::endl;
            break;
        }
    }
    return stream;
}

# endif
