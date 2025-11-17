
#include "Span.hpp"

Span::Span() : m_numbers(), m_N(0) {};

Span::Span(unsigned int N) : m_N(N) {};

Span::Span(const Span &copy) : m_N(copy.m_N), m_numbers(copy.m_numbers) {};

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        m_numbers = other.m_numbers;
        m_N = other.m_N;
    }
    return *this;
};

Span::~Span() {};

void Span::addNumber(int number)
{
    if (m_numbers.size() >= m_N)
        throw std::overflow_error("Cannot add number: Span is full");

    m_numbers.push_back(number);
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    if ((m_numbers.size() + std::distance(begin, end)) > m_N)
        throw std::overflow_error("Cannot add number: Span is full");

    m_numbers.insert(m_numbers.end(), begin, end);
}
