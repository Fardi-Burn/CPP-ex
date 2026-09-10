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


void	RPN::calculate(std::string str)
{
	int result = 0;

	if (str.size() < 2)
	{
		throw (std::string("Error"));
	}
	for (size_t i = 0; i < str.size(); i++)
	{
		if (std::isdigit(str[i]))
			_num_stack.push(str[i] - '0');
		else
		{
			if (_num_stack.size() < 2) 
				throw (std::string("Error"));
			int b = _num_stack.top();
			_num_stack.pop();
			int a = _num_stack.top();
			_num_stack.pop();

			switch (str[i])
			{
					case '+': result = a + b; break;
					case '-': result = a - b; break;
					case '*': result = a * b; break;
					case '/':
			if (b == 0)
				throw (std::string("Error"));
			result = a / b;
			break;
			default:
				throw (std::string("Error"));
			}
			_num_stack.push(result);
		}
	}
	if (_num_stack.size() > 1)
				throw (std::string("Error"));
	std::cout << result << std::endl;
}
