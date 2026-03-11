#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int	main(void)
{
	Animal*	arr[4];

	arr[0] = new Dog();
	arr[1] = new Dog();
	arr[2] = new Cat();
	arr[3] = new Cat();

	arr[0]->setIdeas(10, "Balls!!!");
	arr[1]->setIdeas(1, "FOOD!!!");
	arr[2]->setIdeas(0, "Water eww");
	arr[3]->setIdeas(5, "birds yummy!!!");

	std::cout << std::endl;

	arr[0]->printIdeas();
	arr[1]->printIdeas();
	arr[2]->printIdeas();
	arr[3]->printIdeas();
	std::cout << std::endl;

	for (int i = 0; i < 4; i++)
	{
		delete arr[i];
	}
	return (0);
}
