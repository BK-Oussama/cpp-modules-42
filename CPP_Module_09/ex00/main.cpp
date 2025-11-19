
#include "BitcoinExchange.hpp"

#include <iostream>
#include <iomanip>   // for std::setprecision

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error: could not open file." << std::endl;
        return 0;
    }

    try
    {
        // 1. database management ---> 2. input processing.

        // BitcoinExchange(); (Default constructor) -> Should probably load the data.csv file here.

        // laod the file
        // store the file in a map
        // the class should have std::map (key:: date maybe a string, and a value which is an int price)

        // after loading the DB into our program, we start by reading the full input file and store in a string !!,
        // after we load input file to our program space, we start parsing -- input processing! 
        // if we encounter a line of the give input file that should be calcultes it btc value rate at the time,
        // we store an error message, i do have to figure out a good mechinsim of doing so, should i store the error messag in the key palce or in the value palce or use a difrent approche
        // i may not have to store each line in map, just while parsing the line, i wil extract the date and buying price, and react, either with error or with printing the result of the invetsmnt.
        (void)argv;
        BitcoinExchange btc;
        std::map<std::string, float> f = btc.getDB();


        btc.processInputFile(argv[1]);
        
        // std::map<std::string, float>::iterator it, ite;
        // it = f.begin();
        // ite = f.end();

        // while (it != ite)
        // {
        //     std::cout << "date ----> \t" << it->first << "\tprice ----> \t" << it->second << std::setprecision(2) <<  std::endl;
        //     ++it; 
        // }
        // // it, ite;

        
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }


    return 0;
}