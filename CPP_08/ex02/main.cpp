# include "header.hpp"
# include "MutantStack.hpp"

int main()
{
    try
    {
            {
                std::cout << "--------------- TEST CLASS" << std::endl;
                MutantStack<int> * mstack = new MutantStack<int>();
                MutantStack<int> * mstack2 = new MutantStack<int>();
                srand(time(0));
                std::cout << "Pushing mstack: ";
                for (int i = 0; i < 10; i++)
                {
                    int n = std::rand() % 100;
                    mstack->push(n);
                    std::cout << "|" << n ;
                }
                std::cout << "|" << std::endl;
                std::cout << "Poping mstack\n";
                mstack->pop();
                std::cout << "mstack : " << *mstack;
                std::cout << "mstack2: " << *mstack2;
                std::cout << "--------------- OPERATOR TEST" << std::endl;
                std::cout << "mstack : " << *mstack;
                std::cout << "mstack2: " << *mstack2;
                *mstack2 = *mstack;
                std::cout <<  MAGENTA "operator=" RESET << std::endl;
                std::cout << "mstack : " << *mstack;
                std::cout << "mstack2: " << *mstack2;

                std::cout << "--------------- ITERATORS TEST" << std::endl;
                MutantStack<int>::iterator begin = mstack->begin();
                MutantStack<int>::iterator end = mstack->end();
                std::cout << "begin: " << *begin << std::endl;
                std::cout << "end: " << *(end - 1) << std::endl;
                std::cout << "Printing stack: " << std::endl;
                for (MutantStack<int>::iterator it = begin; it != end; it++)
                    std::cout << "|" << *it;
                std::cout << "|" << std::endl;

                delete mstack;
                delete mstack2;
            }
            {
                std::cout << "--------------- TEST FROM SUBJECT" << std::endl;
                std::cout << "--------------- MUTANT STACK" << std::endl;
                MutantStack<int> mstack;
                mstack.push(5);
                mstack.push(17);
                std::cout << mstack.top() << std::endl;
                mstack.pop();
                std::cout << mstack.size() << std::endl;
                mstack.push(3);
                mstack.push(5);
                mstack.push(737);
                //[...]
                mstack.push(0);
                MutantStack<int>::iterator it = mstack.begin();
                MutantStack<int>::iterator ite = mstack.end();
                ++it;
                --it;
                while (it != ite)
                {
                std::cout << *it << std::endl;
                ++it;
                }
                std::cout << "--------------- stack from mstack" << std::endl;
                std::stack<int> s(mstack);
                std::cout << mstack;
                int n = s.size();
                std::cout << "Printing s\t| size : " << n ;
                for (int i = 0; i < n; i++)
                {
                    std::cout << "|" << s.top(); // prints reverse
                    s.pop();
                }
                std::cout << "|\n";

            }
            {
                std::cout << "--------------- TEST FROM SUBJECT" << std::endl;
                std::cout << "--------------- LIST" << std::endl;
                std::list<int> mstack;
                mstack.push_back(5);
                mstack.push_back(17);
                std::cout << mstack.back() << std::endl;
                mstack.pop_back();
                std::cout << mstack.size() << std::endl;
                mstack.push_back(3);
                mstack.push_back(5);
                mstack.push_back(737);
                //[...]
                mstack.push_back(0);
                std::list<int>::iterator it = mstack.begin();
                std::list<int>::iterator ite = mstack.end();
                ++it;
                --it;
                while (it != ite)
                {
                std::cout << *it << std::endl;
                ++it;
                }
 
            }
            std::cout << "--------------- TEST ADD RANGE" << std::endl;
            {
                
            }
        std::cout << "--------------- END TESTING" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << RESET RED "\nError: " << e.what() << std::endl;
    }
    return 0;
}
