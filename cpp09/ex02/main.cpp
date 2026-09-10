#include "PmergeMe.hpp"
#include <iostream>

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
	}
	catch(std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
		return (1);
	}
	return (0);
}
