#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain	*brain;
	public:
		// Constructors and destructors
		Cat();
		Cat(const Cat& other);
		Cat	&operator=(const Cat& other);
		~Cat();
		// Member Functions
		void		makeSound(void);
		// Setters
		void		setIdeas(int index, const std::string& idea);
		// Gettersvoid
		void	printIdeas(void);
};

#endif
