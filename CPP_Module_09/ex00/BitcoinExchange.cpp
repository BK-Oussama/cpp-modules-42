
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
    if (!std::getline(file, line)) // skip header && check empty file
        throw std::runtime_error("Error: data.csv is empty");

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

    std::string errorMsg = "Error: bad input => " + date;
    if (year.empty() || month.empty() || day.empty())
        throw std::invalid_argument(errorMsg);

    std::stringstream ssy(year);
    std::stringstream ssm(month);
    std::stringstream ssd(day);

    ssy >> Y;
    ssm >> M;
    ssd >> D;

    if (Y < 2009 || Y > 2030) // may change later: we should only check gains curent day you can buy in future !!
        throw std::invalid_argument(errorMsg);

    if (M <= 0 || M > 12)
        throw std::invalid_argument(errorMsg);

    if (D <= 0 || D > 31)
        throw std::invalid_argument(errorMsg);

    return true;
}

bool BitcoinExchange::validateAmount(std::string &amount)
{
    if (amount.empty() || amount.find_first_not_of(" \t\n\r\f\v") == std::string::npos)
        throw std::invalid_argument("Error: not a positive number.");

    float Amount;

    std::istringstream ssa(amount);

    if (!(ssa >> Amount))
        throw std::invalid_argument("Error: not a positive number.");

    if (Amount < 0)
        throw std::invalid_argument("Error: not a positive number.");

    if (Amount > 1000)
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

        std::string Date, Amount;
        std::istringstream string_stream(line);

        std::getline(string_stream, Date, '|');
        std::getline(string_stream, Amount, '|');

        try
        {
            if (!Date.empty())
            {
                size_t last = Date.find_last_not_of(" \t\n\r");
                if (last != std::string::npos)
                    Date = Date.substr(0, last + 1);
            }

            
            validateDate(Date);
            validateAmount(Amount);

            // Returns an iterator to the first element that is ≥ key.
            std::map<std::string, float>::iterator it = m_db.lower_bound(Date);

            if (it->first != Date && it != m_db.begin())
            {
                std::cout << "---------------\n";
                it--;
            }

            std::istringstream ssa(Amount);
            float roi;
            ssa >> roi;
            roi = roi * it->second;

            std::cout << Date << " =>" << Amount << " = " << roi << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }
}
