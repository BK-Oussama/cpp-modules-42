
#include "MutantStack.hpp"

int main()
{

        MutantStack<int> mstack;

        mstack.push(5);
        mstack.push(17);

        std::cout << mstack.top() << std::endl;

        mstack.pop();

        std::cout << mstack.size() << std::endl;

        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        //[...]
        mstack.push(0);

        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();

        *it = 999;
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }

        std::cout << "--------------------------------------------------------------------\n";
        
        std::stack<int> s(mstack);
        while(!s.empty())
        {
            std::cout << s.top() << std::endl;
            s.pop();
        }
        
        
        MutantStack<int> A;
        A.push(42);
        A.push(1337);
        A.push(21);
        A.push(19);
        MutantStack<int>::const_iterator const_it = A.begin();
        MutantStack<int>::const_iterator const_ite = A.end();
        while (const_it != const_ite)
        {
            std::cout << "------->\t" << *const_it << std::endl;
            const_it++;
        }
        
        std::cout << "<----------------------->" << A.top() << std::endl;
        // *const_it = 9;

    return 0;
}
