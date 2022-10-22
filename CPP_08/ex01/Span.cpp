# include "Span.hpp"

Span::Span    (const unsigned int N)
: _N(N)
{
    std::cout << GREEN "Fields Constructor called" RESET << std::endl;
	_array = std::vector<int>();
    return;
}

Span::Span    (void)
: _N(0)
{
    std::cout << GREEN "Default Constructor called" RESET << std::endl;
	_array = std::vector<int>();
    return;
}

Span::Span    (const Span & cpy)
: _N(cpy.getN())
{
    std::cout << GREEN "Copy Constructor called" RESET << std::endl;
    *this = cpy;
    return;
}

Span::~Span   (void)
{
    std::cout << RED "Destructor called" RESET << std::endl;
    return;
}

Span &              Span::operator=(const Span& cpy)
{
    this->~Span();
	new (this) Span(cpy.getN());
    this->_array = cpy.getA();
    return *this;
}

std::ostream&       operator<<(std::ostream& stream, Span& obj)
{
    stream <<  CYAN "Span | Max capacity: " << obj.getN() << " | current: " << (obj.getA()).size() << std::endl;
    if ((obj.getA()).empty() == false)
        std::for_each((obj.getA()).begin(), (obj.getA()).end(), displayUI);
    else
        stream <<  "| array empty !";
    stream <<  "|" RESET << std::endl;
    return stream;
}

const unsigned int&     Span::getN(void)const 
{return _N;}

const std::vector<int>& Span::getA(void)const 
{return _array;}

void                Span::addNumber(int i)
{
    if (this->_array.size() < this->_N)
    {
        if (this->_array.empty() == true)
            this->_array.push_back(i);
        else
        {
            iterator  begin   = this->_array.begin();
            iterator  end     = this->_array.end();
            iterator  upper   = std::upper_bound(begin, end, i);
            if (upper != end)
                this->_array.insert(upper, i);
            else
                this->_array.push_back(i);
        }
    }
    else
        throw std::out_of_range("Array size is already at maximum capacity.");
    return;
}

void                Span::addNumber( void )
{
    if (this->_array.size() < this->_N)
    {
        int i = std::rand() % RAND_RANGE;
        if (this->_array.empty() == true)
            this->_array.push_back(i);
        else
        {
            iterator  begin   = this->_array.begin();
            iterator  end     = this->_array.end();
            iterator  upper   = std::upper_bound(begin, end, i);
            if (upper != end)
                this->_array.insert(upper, i);
            else
                this->_array.push_back(i);
        }
    }
    else
        throw std::out_of_range("Array size is already at maximum capacity.");
    return;
}

void                Span::addRange( void )
{
    std::vector<int> range;
    for (unsigned int i = 0; i < this->_N; i++)
        
        addNumber();
    return;
}

void                Span::addRange(iterator begin, iterator end)
{
    if (begin == end)
        return;
    int toBeAdded = end - begin;
    int available = static_cast<int>(this->_N - this->_array.size());
    if (toBeAdded <= available)
    {
        this->_array.insert(this->_array.end(), begin, end);
        std::sort(this->_array.begin(), this->_array.end());
    }
    else
        throw std::out_of_range("addRange: Array size is already at maximum capacity.");
    return;
}

int                 Span::shortestSpan()
{
    if (this->_array.empty() == true)
        throw std::out_of_range("shortestSpan: Array empty");

	iterator  begin   = (this->_array).begin();
	iterator  end     = (this->_array).end();
    if (end == begin + 1)
        throw std::out_of_range("shortestSpan: Array too small to compute shortest span");

	iterator  it;
    int min = std::abs(*begin - *(begin + 1));
    if (min == 0)
        return min;
    for (it = begin; it != end - 1 ; it++)
    {
        min = std::min(std::abs(*it - *(it + 1)), min);
        if (min == 0)
            return min;
    }
    return min;
}

int                 Span::longestSpan()
{
    if (this->_array.empty() == true)
        throw std::out_of_range("Array empty");
	iterator  beg  = (this->_array).begin();
	iterator  end = (this->_array).end();
    if (end == beg + 1)
        throw std::out_of_range("Array too small to compute shortest span");
    return (*(end - 1) - *beg);
}

// int                 Span::shortestSpan() // old
// {
//     if (this->_array.empty() == true)
//         throw std::out_of_range("Array empty");

// 	iterator  begin  = (this->_array).begin();
// 	iterator  end = (this->_array).end();
// 	iterator  itA;
// 	iterator  itB;

//     if (end == begin + 1)
//         throw std::out_of_range("Array too small to compute shortest span");

//     int min = std::abs(*begin - *(end - 1));
//     for (itA = begin; itA != end; itA++)
//     {
//         for (itB = itA + 1; itB != end; itB++)
//             min = std::min(std::abs(*itA - *itB), min);
//     }
//     return min;
// }

// int                 Span::longestSpan() // old
// {
// 	iterator  it  = (this->_array).begin();
// 	iterator  end = (this->_array).end();
//     int min = *it;
//     int max = *it;

//     while (it != end)
//     {
//         if (min > *it)
//             min = *it;
//         else if (max < *it)
//             max = *it;
//         it++;
//     }
//     return (max - min);
// }
