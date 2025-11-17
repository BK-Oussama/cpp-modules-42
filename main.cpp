#include <iostream>
#include <vector>
#include <iterator> // for std::distance

int main() {
    // Create an empty vector
    std::vector<int> numbers;

    // Fill it manually (C++98 compatible)
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);
    numbers.push_back(40);
    numbers.push_back(50);

    // Define iterators to a subrange
    std::vector<int>::iterator first = numbers.begin() + 1; // points to 20
    std::vector<int>::iterator last = numbers.end() - 1;    // points to 40

    // Use std::distance to calculate the number of elements in the range
    std::ptrdiff_t rangeSize = std::distance(first, last);

    std::cout << "Number of elements in the range: " << rangeSize << std::endl;

    // Optional: iterate over the range and print elements
    for (std::vector<int>::iterator it = first; it != last; ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
