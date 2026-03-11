#include "Brain.hpp"

/////////////////////////////////////////////////////

// Construtcots and destructors

Brain::Brain()
{
	std::cout << "Brain constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destrucotr called" << std::endl;
}

Brain::Brain(const Brain& other)
{
	std::cout << "Copy brain called" << std::endl;
	*this = other;
}

Brain &Brain::operator=(const Brain& other)
{
	std::cout << "Copy assigment brain called" << std::endl;
	std::copy(other.ideas, other.ideas + 100, this->ideas);
	return (*this);
}

/////////////////////////////////////////////////////

// Setters and getters

void	Brain::setIdeas(int index, const std::string& ideas)
{
	if (index >= 0 && index < 100)
		this->ideas[index] = ideas;
}

std::string	Brain::getIdeas(int index)
{
	if (ideas[index].length() > 0)
		return (ideas[index]);
	else 
		return ("");
}

/////////////////////////////////////////////////////
