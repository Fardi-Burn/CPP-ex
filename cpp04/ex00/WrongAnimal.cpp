#include "WrongAnimal.hpp"

///////////////////////////////////////////////

// Constructors and destructors

WrongAnimal::WrongAnimal()
{
	this->type = "";
	std::cout << "Constructor WrongAnimal class" << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& other)
{
	this->type = other.type;
	return (*this);
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	std::cout << "Copy WrongAnimal called" << std::endl;
	if (&other != this)
	{
		this->type = other.type;
		return ;
	}
	return ;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Destructor WrongAnimal class" << std::endl;
}

///////////////////////////////////////////////

// Member Functions

void	WrongAnimal::makeSound(void) const
{
	std::cout << "WrongAnimal has made a sound!" << std::endl;
}

///////////////////////////////////////////////

// Getters 

std::string	WrongAnimal::getType(void) const
{
	return (this->type);
}

///////////////////////////////////////////////
