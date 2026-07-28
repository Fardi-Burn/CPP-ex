#pragma once
# include <exception>
# include <vector>

class Span
{
	private:
		unsigned int		N;
		std::vector<int>	_Nums;
	public:
		Span(unsigned int number);
		~Span();
		Span(const Span &other);
		Span	&operator=(const Span &other);
		void	addNumber(int number);
		int		shortestSpan();
		int		longestSpan();
		class	VectorFullException : public std::exception
		{
			public:
				const char *what() const throw()
				{
					return ("Max size reached");
				}
		};
};
