#include "WrongCat.hpp"

///////////////////////////////////////////////

// Constructors and destructors

WrongCat::WrongCat(void) : WrongAnimal()
{
	this->type = "WrongCat";
	std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
	std::cout << "WrongCat copy called" << std::endl;
	this->type = other.type;
}

WrongCat	&WrongCat::operator=(const WrongCat& other)
{
	if (&other != this)
		this->type = other.type;
	return (*this);
}


WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructor called" << std::endl;
}

///////////////////////////////////////////////

// Member Functions

void	WrongCat::makeSound(void)
{
	std::cout << this->type << " not a meowww!!!" << std::endl;
}

//////////////////////////////////////////////
