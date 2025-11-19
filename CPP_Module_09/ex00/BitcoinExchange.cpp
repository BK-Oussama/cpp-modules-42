
#include "BitcoinExchange.hpp"
#include <sstream>
#include <string>

BitcoinExchange::BitcoinExchange()
{
    std::ifstream file("data.csv");
    if (file.is_open() == 0)
    {
        throw CouldNotOpenFile();
    }

    std::string line;
    std::getline(file, line); // skip header
    while (std::getline(file, line))
    {
        std::string p, Date;

        std::istringstream string_stream(line);

        std::getline(string_stream, Date, ',');
        std::getline(string_stream, p, ',');

        // convert price to float
        std::stringstream ss(p);
        float Price;
        ss >> Price;

        m_db.insert(std::make_pair(Date, Price));
    }

    file.close();
};

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) : m_db(copy.m_db) {};

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
        m_db = other.m_db;
    return *this;
};

BitcoinExchange::~BitcoinExchange() {};

bool BitcoinExchange::validateDate(std::string &date)
{
    int Y, M, D;

    std::string year, month, day;

    std::istringstream string_stream(date);

    std::getline(string_stream, year, '-');
    std::getline(string_stream, month, '-');
    std::getline(string_stream, day, '-');

    if (!year[0] || !month[0] || !day[0])
        return false;

    std::stringstream ssy(year);
    std::stringstream ssm(month);
    std::stringstream ssd(day);

    ssy >> Y;
    ssm >> M;
    ssd >> D;

    if (Y < 2006 || Y > 2030) // may change later: we should only check gains curent day you can buy in future !!
        return false;

    if (M <= 0 || M > 12)
        return false;

    if (D <= 0 || D > 31)
        return false;

    return true;
}

bool BitcoinExchange::validateAmount(std::string &amount)
{
    if (amount.empty() || amount.find_first_not_of(" \t\n\r\f\v") == std::string::npos)
        throw std::invalid_argument("Error: not a positive number.");
        

    float Amount;

    std::istringstream ssa(amount);
    ssa >> Amount;

    if (Amount < 0)
        throw std::invalid_argument("Error: not a positive number.");

    if (Amount >= static_cast<float>(__INT_MAX__))
        throw std::invalid_argument("Error: too large a number.");

    return true;
}

void BitcoinExchange::processInputFile(const char *filename)
{
    std::ifstream file(filename);
    if (file.is_open() == 0)
    {
        throw CouldNotOpenFile();
    }

    std::string line;
    std::getline(file, line); // skip header
    while (std::getline(file, line))
    {
        // extract DATE and VALUE '|'

        std::string Date, Amount;
        std::istringstream string_stream(line);

        std::getline(string_stream, Date, '|');
        std::getline(string_stream, Amount, '|');
        if (validateDate(Date) == false)
        {
            std::cerr << "Error: bad input => " << Date << '\n';
        }

        try
        {
            validateAmount(Amount);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << Amount <<  '\n';
        }

        std::cout << Date << "\t<---->\t" << Amount << std::endl; 


        // if not error search for the nearset DATE (key) and give the estimate return en invetsment.
            // lower_bound
        // process next line
    }
}
