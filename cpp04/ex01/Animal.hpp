#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <string>
# include <iostream>

class Animal
{
	protected:
		std::string type;
		std::string	sound;
	public:
		// Constructors and Destrucors
		Animal();
		virtual ~Animal();
		// Members functions
		virtual void		makeSound() const;
		// Getters
		virtual std::string	getType() const;
		virtual std::string	getSound() const;
};

#endif
