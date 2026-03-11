#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain	*brain;
	public:
		// Constructors and destructors
		Dog();
		Dog(const Dog& other);
		Dog	&operator=(const Dog& other);
		~Dog();
		// member function
		void		makeSound(void);	
		// getters
		void		setIdeas(int index, const std::string &ideas);
		// setters
		void		printIdeas(void);
};

#endif
