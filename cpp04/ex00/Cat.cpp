#include "Cat.hpp"

///////////////////////////////////////////////

// Constructors and destructors

Cat::Cat(void) : Animal()
{
	this->type = "Cat";
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << "Cat copy called" << std::endl;
	this->type = other.type;
}

Cat	&Cat::operator=(const Cat& other)
{
	if (&other != this)
		this->type = other.type;
	return (*this);
}


Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
}

///////////////////////////////////////////////

// Member Functions

void	Cat::makeSound(void) const
{
	std::cout << this->type << " meow!!!" << std::endl;
}

//////////////////////////////////////////////
