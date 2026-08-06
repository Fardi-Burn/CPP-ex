#include "Span.hpp"
#include <algorithm>
#include <climits>
#include <iostream>

Span::Span(unsigned int number)
{
	if (N >= UINT_MAX)
		throw (UintMaxExeption());
	N = number;
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
	{
		throw (NotEnoughNumbersExeption());
	}
	copy = _Nums;
	std::sort(copy.begin(), copy.end());
	smallest = copy[1] - copy[0];
	for (size_t i = 1; i < copy.size() - 1; i++)
	{
		int	diff = copy[i + 1] - copy[i];
		if (diff < smallest)
			smallest = diff;
	}
	return (smallest);
}

int	Span::longestSpan()
{
	std::vector<int>	copy;
	int					biggest;
	int					smallest;

	if (_Nums.size() < 2)
		return (0);
	copy = _Nums;
	std::sort(copy.begin(), copy.end());
	biggest = copy[copy.size() - 1];
	smallest = copy[0];
	int	diff = biggest - smallest;
	return (diff);
}

void	Span::addRange(int begin, int end)
{
	while (begin <= end)
	{
		addNumber(begin);
		begin++;
	}
	return ;
}
