
#ifndef FILEREPLACER_HPP
#define FILEREPLACER_HPP

#include <string>
#include <fstream>
#include <iostream>

class FileReplacer
{
private:
    std::string m_fileName;
    std::string m_search;
    std::string m_replace;

public:
    FileReplacer(const std::string &inputFile, const std::string &search, const std::string &replace);
    bool replaceInFile() const;
};

#endif