#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

////////////////////////////////////////////////////////

// Constructors, Destructor and Copy/assigment

ScavTrap::ScavTrap(std::string new_name)
{
	this->name = new_name;
	this->Hit_points = 100;
	this->Energy_points = 50;
	this->Attack_damage = 20;
	this->type_ct = "ScavTrap";
	this->GateKeeper = 0;
	std::cout	<< "Constructor for ScavTrap called " << type_ct << " " << new_name << " created"  << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	*this = other;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->Hit_points = other.Hit_points;
		this->Energy_points = other.Energy_points;
		this->Attack_damage = other.Attack_damage;
		this->type_ct = other.type_ct;
	}
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "Destructor for ScavTrap called " << this->type_ct << " " << this->name << " destroyed"  << std::endl;
}

////////////////////////////////////////////////////////

// Member Functions

void	ScavTrap::attack(const std::string& target)
{
	if (!this->alive())
	{
		std::cout << this->type_ct << " " << this->name << " cant attacks " << target << " because is at 0 Health Points!!!" << std::endl;
		return ;
	}
	if (Energy_points > 0)
	{
		std::cout << type_ct << " " << this->name << " fires a nuke " << target << ", doing " << this->Attack_damage << " points of damage!" << std::endl;
		this->Energy_points -= 1;
		return ;
	}
	else
	{
		std::cout << type_ct << " " << this->name <<" is lacking energy!!!" << std::endl;
		return ;
	}
}

void	ScavTrap::guardGate(void)
{
	if (this->GateKeeper == 0)
	{
		GateKeeper = true;
		std::cout << type_ct << " " << this->name << " has enter Gate keeper mode!!!" << std::endl;
		return ;
	}
	else
	{
		std::cout << type_ct << " " << this->name << " has deactivated Gate keeper mode!!!" << std::endl;
		GateKeeper = false;
		return ;
	}
}

////////////////////////////////////////////////////////

// Getters

bool	ScavTrap::getGateKeeper(void)
{
	return (this->GateKeeper);
}

////////////////////////////////////////////////////////
