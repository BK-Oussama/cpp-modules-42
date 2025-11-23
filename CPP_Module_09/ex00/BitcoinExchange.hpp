#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <fstream>
#include <iostream>
#include <sstream>
#include <exception>
#include <string>
#include <iomanip> // for std::setprecision

class BitcoinExchange
{
private:
    std::map<std::string, float> m_db;

public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &copy);
    BitcoinExchange &operator=(const BitcoinExchange &other);
    ~BitcoinExchange();

    void processInputFile(const char *file);

    bool validateDate(std::string &date);
    bool validateAmount(std::string &amount);

    class CouldNotOpenFile : public std::exception
    {
    public:
        virtual const char *what() const throw()
        {
            return ("Could not open file");
        }
    };

    const std::map<std::string, float> &getDB() const { return m_db; }; // to be removed later
};

#endif