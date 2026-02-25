#ifndef CLAPTRAP_H
# define CLAPTRAP_H
# include <string>
# include <iostream>

class ClapTrap
{
	protected:
		std::string	name;
		int			Hit_points;
		int			Energy_points;
		int			Attack_damage;
		std::string	type_ct;
	public:
		// Constructors , destructor assigment and =operator
		ClapTrap(void);
		ClapTrap(std::string new_name);
		ClapTrap(const ClapTrap& other);
		ClapTrap& operator=(const ClapTrap& other);
		~ClapTrap();
		// Member Functions
		virtual void		attack(const std::string& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
		bool		alive(void);
		// Getters
		std::string	getName(void);
		int			getHitpoints(void);
		int			getEnergypoints(void);
		int			getAttackdamage(void);
		std::string	gettype_ct(void);
};

#endif
