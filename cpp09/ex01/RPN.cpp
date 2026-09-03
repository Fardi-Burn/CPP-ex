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
		_num_stack= other._num_stack;
	return (*this);
}

// Member functions

void	RPN::string_parser(std::string str)
{
	
}

void	RPN::calculate()
{

}
