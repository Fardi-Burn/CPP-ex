#include "Animal.hpp"

///////////////////////////////////////////////

// Constructors and destructors

Animal::Animal()
{
	this->type = "";
	std::cout << "Constructor Animal class" << std::endl;
}

Animal&	Animal::operator=(const Animal& other)
{
	this->type = other.type;
	return (*this);
}

Animal::Animal(const Animal& other)
{
	std::cout << "Copy animal called" << std::endl;
	if (&other != this)
	{
		this->type = other.type;
		return ;
	}
	return ;
}

Animal::~Animal()
{
	std::cout << "Destructor Animal class" << std::endl;
}

///////////////////////////////////////////////

// Member Functions

void	Animal::makeSound(void) const
{
	std::cout << this->type << " has made a sound!" << std::endl;
}

///////////////////////////////////////////////

// Getters 

std::string	Animal::getType(void) const
{
	return (this->type);
}

///////////////////////////////////////////////
