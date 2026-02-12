#include "Harl.hpp"

Harl::Harl()
{

}

Harl::~Harl()
{

}

void	Harl::complain(std::string level)
{
	if (level == "DEBUG")
		this->debug();
	else if (level == "INFO")
		this->info();
	else if (level == "WARNING")
		this->warning();
	else if (level == "ERROR")
		this->error();
	return ;
}
