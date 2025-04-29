#include <iostream>
#include <string>

// int #include <iostream>

int main()
{
    // int x { 5 };
    // int y { 6 };

    // int& ref { x }; // ref is now an alias for x

    // ref = y; // assigns 6 (the value of y) to x (the object being referenced by ref)
    // // The above line does NOT change ref into a reference to variable y!

    // std::cout << x << '\n'; // user is expecting this to print 5

    int x = -5;
    if (true)
    {
        x = 4;
        std::cout << x << '\n';
    }
    std::cout << x << '\n';

    return 0;
}
