#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int	main(void)
{
	Dog*	arr[2];
	Cat*	arrc[2];

	arr[0] = new Dog();
	arr[1] = new Dog();
	arrc[0] = new Cat();
	arrc[1] = new Cat();

	arr[0]->setIdeas(10, "Balls!!!");
	arr[1]->setIdeas(1, "FOOD!!!");
	arrc[0]->setIdeas(0, "Water eww");
	arrc[1]->setIdeas(5, "birds yummy!!!");

	std::cout << std::endl;

	arr[0]->printIdeas();
	arr[1]->printIdeas();
	arrc[0]->printIdeas();
	arrc[1]->printIdeas();
	std::cout << std::endl;

	for (int i = 0; i < 4; i++)
	{
		delete arr[i];
	}
	return (0);
}
