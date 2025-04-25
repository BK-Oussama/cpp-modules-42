#include <string.h>
#include <string>
#include <iostream>
#include <ctype.h>

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }
    else
    {
        size_t i = 1;
        std::string str;
        while (argv[i])
        {
            str = argv[i];

            size_t j = 0;
            while (j < str.size())
            {
                str[j] = std::toupper(static_cast<unsigned char>(argv[i][j]));
                j++;
            }
            std::cout << str;

            if ((int)i < argc - 1)
                std::cout << " ";
            i++;
        }
        std::cout << std::endl;
    }
    return (0);
}