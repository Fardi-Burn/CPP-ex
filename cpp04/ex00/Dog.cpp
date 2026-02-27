#include "Dog.hpp"

///////////////////////////////////////////////

// Constructors and destructors

Dog::Dog(void)
{
	this->type = "Dog";
	this->sound = "Woof";
	std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
}

///////////////////////////////////////////////
