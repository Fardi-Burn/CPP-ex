#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int	main(void)
{
	Dog *a = new Dog();

	a->setIdeas(10, "Balls!!!");
	std::cout << std::endl;

	a->printIdeas();
	std::cout << "Deep copy test" << std::endl;
	Dog b = *a;
	std::cout << std::endl;
	delete a;
	b.printIdeas();
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	// SECOND TEST
	std::cout << "Array test" << std::endl;

	Animal*	arr[4];

	arr[0] = new Dog();
	arr[1] = new Dog();
	arr[2] = new Cat();
	arr[3] = new Cat();

	std::cout << std::endl;
	for (int i = 0; i < 4; i++)
	{
		delete arr[i];
	}
	return (0);
}
