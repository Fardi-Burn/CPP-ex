#include "Bureaucrat.hpp"
#include <exception>

int	main(void)
{
	std::cout << "----- Constructor with grades too high and low ----" << std::endl;
	try
	{
		Bureaucrat	b("Bob", 150);
		Bureaucrat	c("Frederick", 100);
		std::cout << b << '\n';
		std::cout << c << '\n';

		std::cout << "----- Create form ----" << std::endl;
		Form		f("House plan", 140, 100);
		std::cout << f << '\n';
		std::cout << '\n';

		std::cout << "----- Bob and Frederick try to sign the form ----" << std::endl;
		b.signForm(f);
		c.signForm(f);
	
		std::cout << "----- State of form (sign) ----" << std::endl;
		std::cout << f.getSigned() << "\n";
		c.signForm(f);
	}
	catch(std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
	}

	return (0);
}
