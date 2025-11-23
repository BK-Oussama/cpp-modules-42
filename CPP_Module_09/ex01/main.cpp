

#include "RPN.hpp"

// Example, the infix expression (3 + 4) × 5 is written in RPN as
// 3 4 + 5 × is evaluated as follows: 

// Scan 3: Push 3 onto the stack. Stack: (3)
// Scan 4: Push 4 onto the stack. Stack: (3, 4)
// Scan +: Pop 4 and 3, perform 3 + 4 (result 7), push 7. Stack: (7)
// Scan 5: Push 5 onto the stack. Stack: (7, 5)
// Scan ×: Pop 5 and 7, perform 7 × 5 (result 35), push 35. Stack: (35)
// End: The result is 35.

int main(int argc, char **argv)
{

    if (argc != 2)
    {
        std::cerr << "Enter RPN expression\n";
        return 0;
    }

    try
    {
        RPN A;
        A.EvaluateExpression(argv[1]);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
