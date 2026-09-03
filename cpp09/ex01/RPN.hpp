#pragma once
# include <stack>
# include <string>

class RPN
{
	private:
		std::stack<char>	_stack;
	public:
		RPN();
		~RPN();
		RPN(RPN const &other);
		RPN	operator=(RPN const &other);

		void	stack_maker(std::string str);
		void	calculate();
};
