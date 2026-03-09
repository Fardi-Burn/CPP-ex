#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int	main(void)
{
	const Animal* j = new Dog();
	std::cout << "\n";
	const Animal* i = new Cat();
	std::cout << "\n";

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	std::cout << "\n";
	delete j;
	std::cout << "\n";
	delete i;
	std::cout << "\n";
	return (0);
}
