#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	const Animal* meta = new Animal();
	const WrongAnimal* h = new WrongAnimal();
	std::cout << "\n";
	const Animal* j = new Dog();
	std::cout << "\n";
	const Animal* i = new Cat();
	const WrongAnimal* d = new WrongCat();
	std::cout << "\n";

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	h->makeSound();
	d->makeSound();
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete h;
	std::cout << "\n";
	delete d;
	std::cout << "\n";
	delete meta;
	std::cout << "\n";
	delete j;
	std::cout << "\n";
	delete i;
	std::cout << "\n";
	return (0);
}
