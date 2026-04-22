#include "Cat.hpp"

///////////////////////////////////////////////

// Constructors and destructors

Cat::Cat(void) : Animal()
{
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << "Cat copy called" << std::endl;
	this->type = other.type;
	this->brain = new Brain(*other.brain);
}

Cat	&Cat::operator=(const Cat& other)
{
	if (&other != this)
	{
		this->type = other.type;
		this->brain = new Brain(*(other.brain));
	}
		return (*this);
}


Cat::~Cat(void)
{
	delete this->brain;
	std::cout << "Cat destructor called" << std::endl;
}

///////////////////////////////////////////////

// Member Functions

void	Cat::makeSound(void) const
{
	std::cout << this->type << " meow!!!" << std::endl;
}

//////////////////////////////////////////////////////

// Setters and getters

void	Cat::setIdeas(int index, const std::string& ideas)
{
	this->brain->setIdeas(index, ideas);
	return ;
}

void	Cat::printIdeas(void)
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
