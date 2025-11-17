

#include "easyfind.hpp"
#include <vector>
#include <list>

int main()
{

    {
        std::vector<int> nums;

        nums.push_back(10);
        nums.push_back(99);
        nums.push_back(45);

        try
        {
            std::vector<int>::iterator it = easyfind(nums, 42);
            std::cout << "The value passed exists on the vector container ---> " << *it << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }

    {

        std::list<int> nums;
        nums.push_back(45);
        nums.push_back(42);
        nums.push_back(1);
        nums.push_back(0);
        try
        {
            std::list<int>::iterator it = easyfind(nums, 0);
            std::cout << "The value passed exists on the list container ---> " << *it << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }

    return 0;
}