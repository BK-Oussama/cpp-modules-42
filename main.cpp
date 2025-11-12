#include <iostream>
#include <cstring>

int main()
{
    int *n;
    uintptr_t k;                           // here's int value 3
    // std::string A = reinterpret_cast<float>(n);                          // here's our float variable
    std::cout << sizeof(uintptr_t) <<   "<--------- \t -------->" << sizeof(int *) <<'\n';             // print f (containing the bits from n)

    return 0;
}