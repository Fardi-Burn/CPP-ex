/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rardila- <rardila-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 12:26:56 by rardila-          #+#    #+#             */
/*   Updated: 2026/02/10 12:48:25 by rardila-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP
# include "Weapon.hpp"
# include <string>
# include <iostream>

class HumanB
{
	private:
		std::string	name;
		Weapon		*weapon;
	public:
		HumanB(std::string n);
		~HumanB();
		void	setWeapon(Weapon &weap);
		void	attack(void);
};

#endif