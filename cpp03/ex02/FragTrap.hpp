#ifndef FRAGTRAP_H
# define FRAGTRAP_H
# include <string>
# include <iostream>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		// Constructors , destructor assigment and =operator
		FragTrap(std::string new_name);
		FragTrap(const FragTrap& other);
		FragTrap& operator=(const FragTrap& other);
		~FragTrap();
		// Member Functions
		void		attack(const std::string& target);
		void		highFiveGuys(void);
};

#endif
