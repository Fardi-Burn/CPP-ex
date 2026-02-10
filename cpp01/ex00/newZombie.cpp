#include "Zombie.hpp"

Zombie	*newZombie(std::string name)
{
	Zombie	*nothuman = new Zombie;

	nothuman->set_name(name);
	return (nothuman);
}
