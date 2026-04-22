#include "Dog.hpp"

///////////////////////////////////////////////

// Constructors and destructors

Dog::Dog(void) : Animal()
{
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << "Dog copy called" << std::endl;
	this->type = other.type;
	this->brain = new Brain(*other.brain);
}

Dog& Dog::operator=(const Dog& other)
{
	if (&other != this)
	{
		this->type = other.type;
		this->brain = new Brain(*(other.brain));
	}
		return (*this);
}

Dog::~Dog(void)
{
	delete this->brain;
	std::cout << "Dog destructor called" << std::endl;
}

//////////////////////////////////////////////

/// Member Functions

void	Dog::makeSound(void) const
{
	std::cout << this->type << " woof!!!" << std::endl;
}

//////////////////////////////////////////////

// Setters and getters

void	Dog::setIdeas(int index, const std::string& ideas)
{
	this->brain->setIdeas(index, ideas);
	return ;
}

void	Dog::printIdeas(void)
{
	std::string	str;

	for (int i = 0; i < 100; i++)
	{
		str = this->brain->getIdeas(i);
		if (str.length() > 0)
		{
			std::cout << str << std::endl;
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////
