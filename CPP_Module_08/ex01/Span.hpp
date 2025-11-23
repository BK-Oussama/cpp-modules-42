#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iostream>

class Span
{
private:
    std::vector<int> m_numbers;
    unsigned int m_N;

public:
    Span();
    Span(unsigned int N);
    Span(const Span &copy);
    Span &operator=(const Span &other);
    ~Span();

    void addNumber(int number);
    void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);

    int shortestSpan() const;
    int longestSpan() const;

    int get_vec_size();
};

#endif