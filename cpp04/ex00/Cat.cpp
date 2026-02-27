#include "Cat.hpp"

///////////////////////////////////////////////

// Constructors and destructors

Cat::Cat(void)
{
	this->type = "Cat";
	this->sound = "Meow";
	std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
}

///////////////////////////////////////////////
