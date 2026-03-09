#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <string>
# include <iostream>

class Animal
{
	protected:
		std::string type;
	public:
		// Constructors and Destrucors
		Animal();
		Animal(const Animal& copy);
		Animal& operator=(const Animal& other);
		virtual ~Animal();
		// Members functions
		virtual void		makeSound() const;
		// Getters
		virtual std::string	getType() const;
};

#endif
