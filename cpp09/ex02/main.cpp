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
	}
	catch(std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
		return (1);
	}
	return (0);
}
