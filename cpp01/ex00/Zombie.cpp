#include "Zombie.hpp"

Zombie::Zombie(void)
{
	return ;
}

Zombie::~Zombie(void)
{
	std::cout << "Destroyed " << name << std::endl;
}

void	Zombie::set_name(std::string name)
{
	this->name = name;
}

void	Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ" << std::endl;
}

