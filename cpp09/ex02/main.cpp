#include "PmergeMe.hpp"
#include <iostream>
#include <ctime>

int	main(int argc, char **argv)
{
	if (argc < 2)
	{ 
		std::cout << "Use ./PmergeMe 1 5 2 4 7 ... \n";
		return (1);
	}
	try 
	{
		PmergeMe pmm(argv);
		pmm.correct_argv();
		pmm.special_cases();
		pmm.before_after_print();
		std::cout << std::endl << "N of elements:" << pmm._numbers.size() << std::endl;

		clock_t start = std::clock();
		pmm.sortVector(pmm._vec);
		clock_t end = std::clock();
		double duration_ms = static_cast<double>(end - start) * 1000.0 / CLOCKS_PER_SEC;

		std::cout << "Time to process a range of "
				<< pmm._vec.size()
				<< " elements with std::vector : "
				<< duration_ms << " ms" << std::endl;

		//pmm.printVector(pmm._vec);
		start = std::clock();
		pmm.sortDeque(pmm._deq);
		end = std::clock();
		duration_ms = static_cast<double>(end - start) * 1000.0 / CLOCKS_PER_SEC;
		std::cout << "Time to process a range of "
				<< pmm._deq.size()
				<< " elements with std::deque : "
				<< duration_ms << " ms" << std::endl;

	}
	catch(std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
		return (1);
	}
	return (0);
}
