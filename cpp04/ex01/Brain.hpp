#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <string>

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
		// Member functions
		void		setIdeas(int index, const std::string& idea);
		std::string	getIdeas(void);
		// Getters
};


#endif
