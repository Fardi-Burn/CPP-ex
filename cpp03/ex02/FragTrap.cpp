#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include <string>

////////////////////////////////////////////////////////

// Constructors, Destructor and Copy/assigment

FragTrap::FragTrap(std::string new_name)
{
	this->name = new_name;
	this->Hit_points = 100;
	this->Energy_points = 100;
	this->Attack_damage = 30;
	this->type_ct = "FragTrap";
	std::cout	<< "Constructor called " << type_ct << " " << new_name << "  a new FragTrap has been created"  << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) 
{
	*this = other;
}

FragTrap	&FragTrap::operator=(const FragTrap &other)
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

FragTrap::~FragTrap(void)
{
	std::cout << "Destructor exploted " << this->type_ct << " " << this->name << " into pieces!!!"  << std::endl;
}

////////////////////////////////////////////////////////

// Member Functions

void	FragTrap::attack(const std::string& target)
{
	if (!this->alive())
	{
		std::cout << this->type_ct << " " << this->name << " cant attacks " << target << " because is at 0 Health Points!!!" << std::endl;
		return ;
	}
	if (Energy_points > 0)
	{
		std::cout << type_ct << " " << this->name << " is attacking " << target << ", doing " << this->Attack_damage << " points of damage!" << std::endl;
		this->Energy_points -= 1;
		return ;
	}
	else
	{
		std::cout << type_ct << " " << this->name <<" is lacking energy!!!" << std::endl;
		return ;
	}
}

void	FragTrap::highFiveGuys(void)
{
	std::string	input;

	std::cout << this->name << " wants to high five you!!" << std::endl;
	std::cout << "Write highfive to high five "  << this->name << std::endl; 
	if (std::getline(std::cin, input))
	{
		if (input == "highfive")
		{
			std::cout << "You high five " << this->name << ", " << this->name << " is happy!!!" << std::endl;
			return ;
		}
		else
		{
			std::cout << "You refused to high five" << this->name << " will remember that!!!" << std::endl;
			return ;
		}
	}
	else
		std::cout << "You left " << this->name << " hanging, he will rembember that!!!" << std::endl;
}

////////////////////////////////////////////////////////

// Getters


////////////////////////////////////////////////////////
