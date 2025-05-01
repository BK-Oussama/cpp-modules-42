
#include "fileReplacer.hpp"


// Constructor
FileReplacer::FileReplacer(const std::string &filename, const std::string &search, const std::string &replace)
    : m_fileName(filename), m_search(search), m_replace(replace) {}

// Function to replace occurrences of searchString with replaceString in the file
bool FileReplacer::replaceInFile() const
{
    std::ifstream inputFile(m_fileName);
    if (!inputFile.is_open())
    {
        std::cerr << "Error: Could not open input file: " << m_fileName << std::endl;
        return false;
    }

    std::string outputFileName = m_fileName + ".replace";
    std::ofstream outputFile(outputFileName);
    if (!outputFile.is_open())
    {
        std::cerr << "Error: Could not create output file: " << outputFileName << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(inputFile, line))
    {
        std::string newLine;
        size_t i = 0;
        while (i < line.length())
        {
            if (line.substr(i, m_search.length()) == m_search)
            {
                newLine = newLine + m_replace;   // Append the replacement string
                i = i + m_search.length(); // Skip the length of the search string
            }
            else
            {
                newLine = newLine + line[i]; // Append the current character
                i++;
            }
        }
        outputFile << newLine << '\n';
    }

    inputFile.close();
    outputFile.close();
    return true;
}