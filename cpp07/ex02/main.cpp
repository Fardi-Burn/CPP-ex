#include <iostream>
#include "Array.hpp"

int main()
{
    std::cout << "===== TEST 1: empty array =====" << std::endl;
    Array<int> empty;
    std::cout << "size: " << empty.size() << std::endl;

    std::cout << "\n===== TEST 2: int array =====" << std::endl;
    Array<int> numbers(5);

    for (unsigned int i = 0; i < numbers.size(); i++)
        numbers[i] = i * 10;

    for (unsigned int i = 0; i < numbers.size(); i++)
        std::cout << numbers[i] << std::endl;

    std::cout << "\n===== TEST 3: copy constructor (deep copy) =====" << std::endl;
    Array<int> copy(numbers);

    copy[0] = 999;

    std::cout << "original[0]: " << numbers[0] << std::endl;
    std::cout << "copy[0]: " << copy[0] << std::endl;

    std::cout << "\n===== TEST 4: assignment operator =====" << std::endl;
    Array<int> assigned;
    assigned = numbers;

    assigned[1] = 888;

    std::cout << "original[1]: " << numbers[1] << std::endl;
    std::cout << "assigned[1]: " << assigned[1] << std::endl;

    std::cout << "\n===== TEST 5: string array =====" << std::endl;
    Array<std::string> strs(3);

    strs[0] = "hello";
    strs[1] = "42";
    strs[2] = "cpp07";

    for (unsigned int i = 0; i < strs.size(); i++)
        std::cout << strs[i] << std::endl;

    std::cout << "\n===== TEST 6: out of bounds =====" << std::endl;
    try
    {
        std::cout << numbers[100] << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
