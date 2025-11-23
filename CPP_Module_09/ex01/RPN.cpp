#include "RPN.hpp"

RPN::RPN() {};

RPN::RPN(const RPN &copy) : m_stack(copy.m_stack) {};

RPN &RPN::operator=(const RPN &other)
{
    if (this != &other)
        m_stack = other.m_stack;
    return *this;
}

RPN::~RPN() {}

bool ValidOperator(std::string &token)
{
    if (token == "+" || token == "-" || token == "*" || token == "/")
        return true;
    return false;
}

bool ValidNumber(std::string &token)
{
    if (token.length() == 1 && token[0] >= '0' && token[0] <= '9')
        return true;
    return false;
}

int PerfromOpertion(int left, int right, const std::string &op)
{
    if (op == "+")
        return left + right;
    else if (op == "-")
        return left - right;
    else if (op == "*")
        return left * right;
    else if (op == "/")
    {
        if (right == 0)
            throw std::logic_error("Error: Division by zero is undefined");
        return (left / right);
    }
    return -99999;
}

void RPN::EvaluateExpression(const char *expression)
{
    std::istringstream string_stream(expression);
    std::string token;

    while (string_stream >> token)
    {
        if (ValidNumber(token) == true)
        {
            m_stack.push(std::atoi(token.c_str()));
        }
        else if (ValidOperator(token) == true)
        {
            if (m_stack.size() < 2)
                throw std::logic_error("Error: Not enough operands.");

            int right = m_stack.top();
            m_stack.pop();

            int left = m_stack.top();
            m_stack.pop();

            int result = PerfromOpertion(left, right, token);
            m_stack.push(result);
        }
        else
            throw std::invalid_argument("Error: Invalid argument");
    }

    if (m_stack.size() != 1)
        throw std::logic_error("Error: Too many operands left");

    std::cout << m_stack.top() << std::endl;
}
