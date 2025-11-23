#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <istream>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <stdexcept>

class RPN
{
private:
    std::stack<int> m_stack;
    std::string line;

public:
    RPN();
    RPN(const RPN &copy);
    RPN &operator=(const RPN &other);
    ~RPN();

    void EvaluateExpression(const char *expression);
};

bool ValidOperator(std::string &token);
bool ValidNumber(std::string &token);
int PerfromOpertion(int left, int right, const std::string &op);

#endif