#ifndef	ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>
# include <string>

class	Zombie
{
	private:
		std::string	name;
	public:
		Zombie(void);
		~Zombie();
		void	set_name(std::string name);
		void	announce(void);
};

void	randomChump(std::string name);
Zombie	*newZombie(std::string name);

#endif
