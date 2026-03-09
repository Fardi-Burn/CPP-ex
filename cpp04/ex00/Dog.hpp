#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"

class Dog : public Animal
{
	public:
		// Constructors and destructors
		Dog();
		Dog(const Dog& other);
		Dog	&operator=(const Dog& other);
		~Dog();
		// member function
		void	makeSound(void);
};

#endif
