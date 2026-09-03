#include "RPN.hpp"
#include <iostream>

int	main(int argc, char **argv)
{

	if (argc != 2)
	{
		std::cout << "Incorrect number of arguments" << std::endl;
		return (1);
	}
	std::string str(argv[1]);
	RPN	rpn;
	try
	{
		rpn.string_parser(str);
		
	}
	catch (const std::exception&) {
	}
}
