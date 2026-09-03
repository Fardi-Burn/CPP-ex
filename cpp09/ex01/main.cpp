#include "RPN.hpp"
#include <iostream>
#include <algorithm>

int	main(int argc, char **argv)
{

	if (argc != 2)
	{
		std::cout << "Incorrect number of arguments" << std::endl;
		return (1);
	}
	std::string str(argv[1]);
	RPN rpn;
	try
	{
		str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
		rpn.calculate(str);
	}
	catch (std::string error) 
	{
		std::cout << error << std::endl;
	}
	return (0);
}
