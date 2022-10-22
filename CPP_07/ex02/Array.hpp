#ifndef ARRAY_H
#define ARRAY_H

# include "header.hpp"
# include "Exceptions.hpp"

template <typename T>
class Array
{
    public:
                    Array();
                    Array(unsigned int size);
                    Array(Array & cpy);
                    ~Array();

        T*          getA() const;
        int         size() const;
        std::string getT() const;
        void        setA(const T& val);
        
        
        Array&      operator=(Array & rhs);
        T&          operator[](int i);
        const T&    operator[](int i) const;

    private:
        T*          _array;
        int         _size;
        std::string _type;
        class OutOfRange : public Exceptions::OutOfRangeException {};
};

template <typename T>
std::ostream&	operator<<(std::ostream& stream, const Array<T> & obj);

#endif