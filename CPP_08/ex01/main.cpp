# include "header.hpp"
# include "Span.hpp"

int main(int ac, char ** av)
{
    try
    {
        std::cout << "--------------- BEGIN TESTING" << std::endl;
        if (ac == 2)
        {

            std::cout << "User input (array range): " << av[1] << std::endl;
            long unsigned int n = std::stoul(av[1]);
            if (n > std::numeric_limits<unsigned int>::max() ||
                n < std::numeric_limits<unsigned int>::lowest())
                throw std::invalid_argument("Invalid argument. Sized of range should be between 0 and 4294967295.");
            unsigned int N = static_cast<unsigned int>(n);
            {
                std::cout << "--------------- TEST CLASS" << std::endl;
                srand(time(0));
                Span * sp = new Span(N);
                sp->addRange();
                std::cout << *sp;
                std::cout << "Shortest Span: " << sp->shortestSpan() << std::endl;
                std::cout << "Longest Span: " << sp->longestSpan() << std::endl;

                srand(time(0));
                Span * sp2 = new Span(N / 2);
                for (unsigned int i = 0; i < (N / 2); i++)
                    sp2->addNumber();
                std::cout << *sp2;
                std::cout << "Shortest Span: " << sp2->shortestSpan() << std::endl;
                std::cout << "Longest Span: " << sp2->longestSpan() << std::endl;

                delete sp;
                delete sp2;
            }
            {
                std::cout << "--------------- TEST FROM SUBJECT" << std::endl;
                Span sp = Span(5);
                sp.addNumber(6);
                sp.addNumber(3);
                sp.addNumber(17);
                sp.addNumber(9);
                sp.addNumber(11);
                std::cout << sp.shortestSpan() << std::endl;
                std::cout << sp.longestSpan() << std::endl;
            }
            std::cout << "--------------- TEST ADD RANGE" << std::endl;
            {
                // unsigned int test = N / 2; // full
                unsigned int test = N / 3; // partial
                // unsigned int test = N *3; // over
                std::vector<int> range (test, 1000);
                std::cout << "Printing range: (size : "<< range.size() <<")" << std::endl;
                for_each(range.begin(), range.end(), displayI);
                std::cout << std::endl << std::endl;

                Span * sp = new Span(N);
                std::cout << "Printing span: " << std::endl;
                std::cout << *sp << std::endl << std::endl;

                std::cout << "adding nb: "<< std::endl;
                if (test > sp->getN())
                    test = sp->getN() / 2;
                for (unsigned int i = 0; i < test; i++)
                    sp->addNumber();
                std::cout << *sp;

                std::cout << "adding range: (to be added : "<< (range.size()) << ")" << std::endl;
                sp->addRange(range.begin(), range.end());
                std::cout << *sp;

                delete sp;
            }
        }
        else
            throw std::invalid_argument("Invalid number of argument. Please enter 1 argument.");
        std::cout << "--------------- END TESTING" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << RESET RED "\nError: " << e.what() << std::endl;
    }
    return 0;
}
