# include "header.hpp"
# include "easyfind.hpp"

void displayInt(int i)
{
	std::cout << "| " << i << std::endl;
	return;
}

int main( void )
{
    {
        std::cout << "---------------" << std::endl;
        std::cout << "Testing";
        std::vector<int>            container; std::cout << MAGENTA " std::vector<int> " RESET << std::endl;
        // std::deque<int>             container; std::cout << MAGENTA " std::deque<int> " RESET << std::endl;
        // std::list<int>              container; std::cout << MAGENTA " std::list<int> " RESET << std::endl;

        for (size_t count=0; count < 6; ++count)
            container.push_back(10 - count);

        std::cout << "Printing container values" << std::endl;
        std::cout << "| Size: " << container.size() << std::endl;
        for_each(container.begin(), container.end(), displayInt);

        std::cout << "--------------- EASYFIND" << std::endl;
        try
        {
            for (int n = 10; n <= 10; n--)
                std::cout << "Looking for " << n << "\t| easyfind ret: " << ::easyfind(container, n) << std::endl;
        }
        catch (const std::exception& e)
        {
            std::cerr << BRED "Error: "  << e.what() << RESET << std::endl;
        }
        std::cout << "---------------" << std::endl;
    }

    return 0;
}