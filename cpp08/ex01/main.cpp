#include "Span.hpp"
#include <iostream>

int main()
{
	try
	{
	
Span sp = Span(8);
sp.addNumber(6);
sp.addNumber(-10);
sp.addNumber(-11);
sp.addNumber(3);
sp.addNumber(17);
sp.addNumber(9);
sp.addNumber(30);
sp.addNumber(11);
std::cout << sp.shortestSpan() << std::endl;
std::cout << sp.longestSpan() << std::endl;
	}
	catch(std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
	}
	std::cout << "\n";
	try 
	{
		Span second = Span(10000);
		second.addRange(1, 10000);
		std::cout << second.shortestSpan() << std::endl;
		std::cout << second.longestSpan() << std::endl;
	}
	catch(std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
	}
return 0;
}
