
#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error: could not open file." << std::endl;
        return 0;
    }

    try
    {
        BitcoinExchange btc;

        std::map<std::string, float> f = btc.getDB();

        btc.processInputFile(argv[1]);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}