#pragma once
# include <stack>
# include <string>
# include <iostream>

class RPN
{
	private:
		std::stack<int>	_num_stack;
	public:
		RPN();
		~RPN();
		RPN(RPN const &other);
		RPN	operator=(RPN const &other);

		void	calculate(std::string str);
};
