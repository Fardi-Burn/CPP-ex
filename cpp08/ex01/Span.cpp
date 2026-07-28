#include "Span.hpp"
#include <algorithm>
#include <iostream>

Span::Span(unsigned int number) : N(number)
{

}

Span::~Span()
{

}

Span::Span(const Span &other)
    : N(other.N), _Nums(other._Nums)
{

}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        N = other.N;
        _Nums = other._Nums;
    }
    return (*this);
}

void	Span::addNumber(int number)
{
	if (_Nums.size() == N)
		throw (VectorFullException());
	_Nums.push_back(number);
}

int	Span::shortestSpan()
{
	std::vector<int>	copy;
	int					smallest;

	if (_Nums.size() < 2)
		return (0);
	copy = _Nums;
	for (std::vector<int>::iterator it = copy.begin(); it < copy.end(); ++it)
	{
		if (copy[it - 1] - copy[it])
	}
}

int	Span::longestSpan()
{
	std::vector<int>	copy;
	int					biggest;
	int					smallest;

	if (_Nums.size() < 2)
		return (0);
	copy = _Nums;
	return (0);
}
