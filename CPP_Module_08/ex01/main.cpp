
#include "Span.hpp"

int main()
{
    // subject example
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }

    std::cout << "-----------------------------------------------------\n";

    {

        Span empty(42);
        try
        {
            empty.addNumber(9);
            empty.shortestSpan();
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }

        Span full(3);
        try
        {
            full.addNumber(12);
            full.addNumber(9);
            full.addNumber(3);
            full.addNumber(1);
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }

    std::cout << "-----------------------------------------------------\n";

    // testing optimized addNumber()
    {

        std::vector<int> v1;
        int i = 0;
        std::srand(time(NULL));
        while (i < 50)
        {
            int rndm_num = rand() % 1000;
            v1.push_back(rndm_num);
            i++;
        }

        try
        {
            Span S1(50);
            S1.addNumber(v1.begin(), v1.end());
            std::cout << "Shortest Span Is:\t" << S1.shortestSpan() << std::endl;
            std::cout << "Longest Span Is:\t" << S1.longestSpan() << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    return 0;
}