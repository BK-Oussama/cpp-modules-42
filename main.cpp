#include <iostream>
#include <cstring>
#include <stdint.h>

// int main()
// {
//     int n = 42;
//     std::string *k;
//     // uintptr_t k;                           // here's int value 3
//     // std::string A = reinterpret_cast<float>(n);                          // here's our float variable
//     std::cout << sizeof(uintptr_t) <<   "<--------- \t -------->" << sizeof(int *) <<'\n';             // print f (containing the bits from n)

//     std::cout << "--------------->\t" << reinterpret_cast<int *>(k) << std::endl;
//     k++;
//     std::cout << "--------------->\t" << (k) << std::endl; 


//     return 0;
// }


// CPP program to demonstrate working of 
// reinterpret_cast
#include <iostream>
using namespace std;

// int main()
// {
//     int* p = new int(65);
//     cout << p << endl;

//     char* ch;
//     cout << &ch << endl;

//     ch = reinterpret_cast<char*>(p);
//     cout << *p << endl;
//     cout << *ch << endl;
//     cout << p << endl;
//     cout << &ch << endl;
//     return 0;
// }

// CPP code to illustrate using structure
#include <bits/stdc++.h>
using namespace std;

// creating structure mystruct
struct mystruct {
    int x;
    int y;
    char c;
    bool b;
};

int main()
{
    mystruct s;

    // Assigning values
    s.x = 5;
    s.y = 10;
    s.c = 'a';
    s.b = true;

    // data type must be same during casting
    // as that of original

    // converting the pointer of 's' to,
    // pointer of int type in 'p'.
    int *p = reinterpret_cast<int *>(&s);

    cout << "size of struct is " << sizeof(s) << endl;
    cout << "adress size of struct is " << sizeof(&s) << endl;
    cout << "int size of " << sizeof(p) << endl;
    cout << "int size of " << sizeof(int) << endl;



    // printing the value currently pointed by *p
    cout << *p << endl;

    // incrementing the pointer by 1
    p++;

    // printing the next integer value
    cout << *p << endl;

    p++;

    // we are casting back char * pointed
    // by p using char *ch.
    char* ch = reinterpret_cast<char*>(p);

    // printing the character value
    // pointed by (*ch)
    cout << *ch << endl;

    ch++;

    /* since, (*ch) now points to boolean value,
    so it is required to access the value using 
    same type conversion.so, we have used 
    data type of *n to be bool. */

    bool* n = reinterpret_cast<bool*>(ch);
    cout << *n << endl;

    // we can also use this line of code to
    // print the value pointed by (*ch).
    cout << *(reinterpret_cast<bool*>(ch));

    return 0;
}

#include <iostream>
#include <iomanip>
