

#include "fileReplacer.hpp"


int main (int argc, char **argv)
{
    if (argc < 4)
    {
        std::cout << "incorect args" << std::endl;
        return 1;
    }

    FileReplacer ops = FileReplacer(argv[1], argv[2], argv[3]);
    ops.replaceInFile();
    return 0;
}