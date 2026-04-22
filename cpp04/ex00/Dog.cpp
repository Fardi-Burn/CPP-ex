#include "Dog.hpp"

///////////////////////////////////////////////

// Constructors and destructors

Dog::Dog(void) : Animal()
{
	this->type = "Dog";
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << "Dog copy called" << std::endl;
	this->type = other.type;
}

Dog& Dog::operator=(const Dog& other)
{
	if (&other != this)
		this->type = other.type;
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
}

//////////////////////////////////////////////

/// Member Functions

void	Dog::makeSound(void) const
{
	std::cout << this->type << " woof!!!" << std::endl;
}

//////////////////////////////////////////////
