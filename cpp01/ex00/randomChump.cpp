#include "Zombie.hpp"

void	randomChump(std::string name)
{
	Zombie	nothuman;
	nothuman.set_name(name);
	nothuman.announce();
	return ;
}
