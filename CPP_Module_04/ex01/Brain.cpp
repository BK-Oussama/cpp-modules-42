

#include "Brain.hpp"
#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain constructed\n";
}

Brain::~Brain()
{
    std::cout << "Brain destroyed\n";
}

Brain::Brain(const Brain &other)
{
    int i = 0;
    while (i < 100)
    {
        m_ideas[i] = other.m_ideas[i];
        i++;
    }
    std::cout << "Brain copied\n";
}

Brain &Brain::operator=(const Brain &other)
{
    if (this != &other)
    {
        int i = 0;
        while (i < 100)
        {
            m_ideas[i] = other.m_ideas[i];
            i++;
        }
    }
    return *this;
}

void Brain::setIdea(int index, const std::string &idea)
{
    if (index >= 0 && index < 100)
        m_ideas[index] = idea;
}

std::string Brain::getIdea(int index) const
{
    if (index >= 0 && index < 100)
        return m_ideas[index];
    else
        return "";
}
