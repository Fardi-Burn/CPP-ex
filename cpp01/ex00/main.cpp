#include "Zombie.hpp"
#include <string>
#include <iostream>

int	main(void)
{
	Zombie		*nothuman;
	std::string	input;

	std::cout 	<< "First Zombie name using newZombie" << std::endl;
	std::getline(std::cin, input);
	nothuman = newZombie(input);
	nothuman->announce();
	delete nothuman;
	std::cout 	<< std::endl << "Second Zombie name using randomChump" << std::endl 
				<< "(deletes at the end of funcion)" << std::endl;
	std::getline(std::cin, input);
	randomChump(input);
	return (0);
}
