#include "ClapTrap.hpp"

////////////////////////////////////////////////////////

// Constructors, Destructor and Copy/assigment

ClapTrap::ClapTrap(std::string new_name) : name(new_name) ,Hit_points(10), Energy_points(10) ,Attack_damage(0)
{
	std::cout	<< "Constructor called " << new_name << " created"  << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	*this = other;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->Hit_points = other.Hit_points;
		this->Energy_points = other.Energy_points;
		this->Attack_damage = other.Attack_damage;
	}
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor called " << this->name << " destroyed"  << std::endl;
}

////////////////////////////////////////////////////////

// Member Functions

bool	ClapTrap::alive(void)
{
	if (this->Hit_points < 1)
	{
		return (0);
	}
	return (1);
}

void	ClapTrap::attack(const std::string& target)
{
	if (!this->alive())
	{
		std::cout << "ClapTrap " << this->name << " cant attacks " << target << " because is broken!!!" << std::endl;
		return ;
	}
	if (Energy_points > 0)
	{
		std::cout << "ClapTrap " << this->name << " attacks " << target << ", doing " << this->Attack_damage << " points of damage!" << std::endl;
		this->Energy_points -= 1;
		return ;
	}
	else
	{
		std::cout << "ClapTrap " << this->name <<" not enough energy to attack!!!" << std::endl;
		return ;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (!this->alive())
	{
		std::cout << "ClapTrap " << this->name << " is already broken!!!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage!!!" << std::endl;
	this->Hit_points -= amount;
	if (this->Hit_points < 1)
	{
		std::cout << "ClapTrap " << this->name << " has fallen!!! and he cant get up!!!" << std::endl;
	}
	return ;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!this->alive())
	{
		std::cout << "ClapTrap " << this->name << " cant repair itself beacuse " << this->getName() << " is broken!!!" << std::endl;
		return ;
	}
	if (Energy_points > 0)
	{
		std::cout << "ClapTrap " << this->name << " repairs itself by " << amount << " hit points!!!" << std::endl;
		this->Hit_points += amount;
		this->Energy_points -= 1;
		return ;
	}
	else
	{
		std::cout << "ClapTrap " << this->name << " doesnt have enough energy to repair itself!!!" << std::endl;
		return ;
	}
}


////////////////////////////////////////////////////////

// Getters

std::string	ClapTrap::getName(void)
{
	return (this->name);
}

int	ClapTrap::getHitpoints(void)
{
	return (this->Hit_points);
}

int ClapTrap::getEnergypoints(void)
{
	return (this->Energy_points);
}

int	ClapTrap::getAttackdamage(void)
{
	return (this->Attack_damage);
}

////////////////////////////////////////////////////////
