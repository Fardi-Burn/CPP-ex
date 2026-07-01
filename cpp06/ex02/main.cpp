#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base	*generate(void)
{

	int chance = std::rand() % 3;
	if (chance == 0)
	{
		Base *_a = new A;
		return (_a);
	}
	else if (chance == 1)
	{
		Base *_b = new B;
		return (_b);
	}
	else
	{
		Base *_c = new C;
		return (_c);
	}
}

void	identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void	identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return ;
	}
	catch (std::exception &)
	{

	}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return ;
	}
	catch (std::exception &)
	{

	}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return ;
	}
	catch (std::exception &)
	{

	}
}

int	main()
{
	std::srand(std::time(NULL) + std::clock());
	
	Base *a;
	Base *b;
	Base *c;

	a = generate();
	b = generate();
	c = generate();
	
	std::cout << "First function" << std::endl;
	identify(a);
	identify(b);
	identify(c);
	std::cout << "Second function" << std::endl;
	identify(*a);
	identify(*b);
	identify(*c);

	
	delete a;
	delete b;
	delete c;
	return (0);
}
