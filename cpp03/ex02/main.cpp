#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	FragTrap	a("FR4G-TP");
	std::string	enemy = "Gr3n4d3";

	std::cout << std::endl;

	// Showing actions
	std::cout << a.getName() << " found his nemesis " << enemy << ", " << a.getName() << " procceds to engage into battle" << std::endl;
	a.attack(enemy);
	std::cout << enemy << " is going to attack!!!" << std::endl;
	a.takeDamage(4);
	a.beRepaired(5);	
	std::cout << enemy << " is going to attack!!!" << std::endl;
	a.takeDamage(2);
	std::cout << std::endl;
	
	std::cout << std::endl;
	// No energy and getting downed
	std::cout << enemy << " is goint to attack!!!" << std::endl;
	a.takeDamage(10);
	a.beRepaired(3);
	std::cout << enemy << " is going to attack!!!" << std::endl;
	a.takeDamage(10);
	a.beRepaired(3);
	a.attack(enemy);

	std::cout << std::endl;
	a.highFiveGuys();
	std::cout << std::endl;
	a.highFiveGuys();
	std::cout << std::endl;
	a.highFiveGuys();
	
	std::cout << std::endl;
	std::cout << "The battle ended!!!" << std::endl;
	std::cout << std::endl;
	

	return (0);
}
