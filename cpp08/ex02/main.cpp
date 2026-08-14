#include "MutantStack.hpp"
#include <iostream>

int main()
{
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << mstack.top() << std::endl;

    mstack.pop();

    std::cout << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

	std::cout << "++ and -- test\n";
	std::cout << *it << " ++test" << std::endl;
	++it;
	std::cout << *it << std::endl;
	std::cout << " --test" << std::endl;
	--it;
	std::cout << *it << std::endl;
	
	
	std::cout << "Print all numbers test\n";
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }


    std::cout << "\n========== RBEGIN / REND TEST ==========" << std::endl;

    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();

    std::cout << "rbegin(): " << *rit << std::endl;

    std::cout << "Reverse contents:" << std::endl;

    while (rit != rite)
    {
        std::cout << *rit << std::endl;
        ++rit;
    }
	
	
	std::cout << "\n========== EMPTY STACK ==========" << std::endl;

    MutantStack<int> empty;

    std::cout << "Empty: " << empty.empty() << std::endl;
    std::cout << "Size: " << empty.size() << std::endl;


}
