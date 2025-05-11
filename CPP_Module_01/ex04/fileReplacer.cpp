
#include "fileReplacer.hpp"


// Constructor
fileReplacer::fileReplacer(const std::string &filename, const std::string &search, const std::string &replace)
    : m_fileName(filename), m_search(search), m_replace(replace) {}

// Function to replace occurrences of searchString with replaceString in the file
bool fileReplacer::replaceInFile() const
{
    std::ifstream inputFile((m_fileName.c_str()));
    if (!inputFile.is_open())
    {
        std::cerr << "Error: Could not open input file: " << m_fileName << std::endl;
        return false;
    }

    std::string outputFileName = m_fileName + ".replace";
    std::ofstream outputFile(outputFileName.c_str());
    if (!outputFile.is_open())
    {
        std::cerr << "Error: Could not create output file: " << outputFileName << std::endl;
        return false;
    }


    std::string line;
    while (std::getline(inputFile, line))
    {
        std::string newLine;
        size_t pos = 0;
        size_t found;

        while ((found = line.find(m_search, pos)) != std::string::npos)
        {
            // Append part before found string
            newLine = newLine + line.substr(pos, found - pos);

            // Append replacement string
            newLine = newLine + m_replace;

            // Move past the found string
            pos = found + m_search.length();
        }

        // Append the remaining part of the line after the last match
        newLine = newLine + line.substr(pos);

        // Write the result line to the output file
        outputFile << newLine << '\n';
    }

    inputFile.close();
    outputFile.close();
    return true;
}