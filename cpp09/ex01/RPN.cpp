#include "RPN.hpp"

RPN::RPN()
{

}

RPN::~RPN()
{

}

RPN::RPN(RPN const &other)
{
	if (this != &other)
		*this = other;
}

RPN	RPN::operator=(RPN const &other)
{
	if (this != &other)
		_stack = other._stack;
	return (*this);
}

// Member functions

void	RPN::stack_maker(std::string str)
{

}
