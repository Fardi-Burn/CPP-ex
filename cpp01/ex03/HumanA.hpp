/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rardila- <rardila-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 12:05:13 by rardila-          #+#    #+#             */
/*   Updated: 2026/02/10 12:42:00 by rardila-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP
# include "Weapon.hpp"
# include <string>
# include <iostream>

class HumanA
{
	private:
		std::string	name;
		Weapon		&weapon;
	public:
		HumanA(std::string n, Weapon &weap);
		~HumanA();
		void	attack(void);
};

#endif