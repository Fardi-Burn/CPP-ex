#ifndef SCAVTRAP_H
# define SCAVTRAP_H
# include <string>
# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:
		bool		GateKeeper;
	public:
		// Constructors , destructor assigment and =operator
		ScavTrap(std::string new_name);
		ScavTrap(const ScavTrap& other);
		ScavTrap& operator=(const ScavTrap& other);
		~ScavTrap();
		// Member Functions
		void		attack(const std::string& target) override;
		void		guardGate();
		// Getters
		bool		getGateKeeper(void);
};

#endif
