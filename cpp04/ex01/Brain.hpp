#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <string>
# include <iostream>

class Brain
{
	private:
		std::string	ideas[100];
	public:
		// Constructor and destructor
		Brain();
		~Brain();
		Brain(const Brain& other);
		Brain	&operator=(const Brain& other);
		// Setters
		void		setIdeas(int index, const std::string& idea);
		// Gettersvoid
		std::string	getIdeas(int index);
};

#endif
