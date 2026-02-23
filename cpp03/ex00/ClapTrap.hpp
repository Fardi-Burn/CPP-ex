#ifndef CLAPTRAP_H
# define CLAPTRAP_H
# include <string>
# include <iostream>

class ClapTrap
{
	private:
		std::string	name;
		int			Hit_points;
		int			Energy_points;
		int			Attack_damage;
	public:
		// Constructors , destructor assigment and =operator
		ClapTrap(std::string new_name);
		ClapTrap(const ClapTrap& other);
		ClapTrap& operator=(const ClapTrap& other);
		~ClapTrap();
		// Member Functions
		void		attack(const std::string& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
		bool		alive(void);
		std::string	getName(void);
		int			getHitpoints(void);
		int			getEnergypoints(void);
		int			getAttackdamage(void);
};

#endif
