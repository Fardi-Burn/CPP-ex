#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include <string>
# include <iostream>

class WrongAnimal
{
	protected:
		std::string type;
	public:
		// Constructors and Destrucors
		WrongAnimal();
		WrongAnimal(const WrongAnimal& copy);
		WrongAnimal& operator=(const WrongAnimal& other);
		virtual ~WrongAnimal();
		// Members functions
		void		makeSound() const;
		// Getters
		virtual std::string	getType() const;
};

#endif
