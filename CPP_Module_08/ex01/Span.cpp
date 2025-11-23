
#include "Span.hpp"

Span::Span() : m_numbers(), m_N(0) {};

Span::Span(unsigned int N) : m_N(N) {};

Span::Span(const Span &copy) : m_numbers(copy.m_numbers), m_N(copy.m_N) {};

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
        throw std::overflow_error("Error: Cannot add number: Span is full");

    m_numbers.push_back(number);
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    if ((m_numbers.size() + std::distance(begin, end)) > m_N)
        throw std::overflow_error("Error: Cannot add number: Span is full");

    m_numbers.insert(m_numbers.end(), begin, end);
}

int Span::shortestSpan() const
{
    if (m_numbers.size() < 2)
        throw std::logic_error("Error: Not enough elements. Minimum required is two.");

    std::vector<int> sorted = m_numbers;

    std::sort(sorted.begin(), sorted.end());

    int min_span = std::abs(sorted[0] - sorted[1]);

    size_t i = 1;
    while (i < sorted.size() - 1)
    {
        int span = std::abs(sorted[i] - sorted[i + 1]);

        if (span < min_span)
            min_span = span;
        i++;
    }

    return min_span;
}

int Span::longestSpan() const
{
    if (m_numbers.size() < 2)
        throw std::logic_error("Error: Not enough elements. Minimum required is two.");

    int min = *std::min_element(m_numbers.begin(), m_numbers.end());
    int max = *std::max_element(m_numbers.begin(), m_numbers.end());

    return (max - min);
}

int Span::get_vec_size()
{
    return (m_numbers.size());
}