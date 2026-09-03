#pragma once
# include <stack>
# include <string>

class RPN
{
	private:
		std::stack<int>	_num_stack;
	public:
		RPN();
		~RPN();
		RPN(RPN const &other);
		RPN	operator=(RPN const &other);

		void	string_parser(std::string str);
		void	calculate();
};
