#include "Bureaucrat.hpp"
#include <exception>

int	main(void)
{
	std::cout << "----- Constructor with grades too high and low ----" << std::endl;
	try
	{
		Bureaucrat b("Bob", 160);
		std::cout << "----- It shouldnt reach here -----" << std::endl;
	}
	catch(std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
	}

	try
	{
		Bureaucrat c("Jhon", 0);
		std::cout << "----- It shouldnt reach here -----" << std::endl;
	}
	catch(std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
	}

	std::cout << "----- Increment and decrement grade func and << operand ----" << std::endl;

	try
	{
		Bureaucrat d("Doe", 1);
		std::cout << d << std::endl;
		d.decrementGrade();
		std::cout << d << std::endl;
		std::cout << "----- Increment grade by 2 to trigger throw -----" << std::endl;
		d.incrementGrade();
		d.incrementGrade();
	}
	catch(std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
	}

	return (0);
}
