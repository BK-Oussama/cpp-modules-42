
#include "fileReplacer.hpp"

int main(int argc, char **argv)
{
    if (argc < 4)
    {
        std::cout << "incorrect args" << std::endl;
        return 1;
    }

    fileReplacer ops(argv[1], argv[2], argv[3]);

    if (!ops.replaceInFile())
        return 1;

    return 0;
}