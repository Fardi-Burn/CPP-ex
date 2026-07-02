#include "iter.hpp"
#include <string>
#include <iostream>

void	printstr(std::string &str)
{
	std::cout << str << std::endl;
}

int	main()
{
	std::string strs[] = {"Hola", "Mundo", "Que tal estas?"};

	iter(strs, 3, printstr);
	return (0);
}
