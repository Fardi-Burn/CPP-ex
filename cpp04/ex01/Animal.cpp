#include "Animal.hpp"

///////////////////////////////////////////////

// Constructors and destructors

Animal::Animal()
{
	this->type = "";
	this->sound = "";
	std::cout << "Constructor Animal class" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Destructor Animal class" << std::endl;
}

///////////////////////////////////////////////

// Member Functions

void	Animal::makeSound(void) const
{
	std::cout << this->sound << std::endl;
}

///////////////////////////////////////////////

// Getters 

std::string	Animal::getType(void) const
{
	return (this->type);
}

std::string	Animal::getSound(void) const
{
	return (this->sound);
}

///////////////////////////////////////////////
