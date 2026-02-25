#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap	a("SC4V-TP");
	std::string	enemy = "Rust";

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
	
	// Using all energy
	std::cout << std::endl;
	std::cout << a.getName() << " is going to do a flurry of attacks!!!" << std::endl;
	a.attack(enemy);
	a.attack(enemy);
	a.attack(enemy);
	a.attack(enemy);
	a.attack(enemy);
	a.attack(enemy);
	a.attack(enemy);
	a.attack(enemy);
	a.attack(enemy);
	a.attack(enemy);

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
	std::cout << "The battle ended!!!" << std::endl;
	std::cout << std::endl;
	

	return (0);
}
