/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rardila- <rardila-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 12:11:40 by rardila-          #+#    #+#             */
/*   Updated: 2026/02/10 12:45:15 by rardila-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string n, Weapon &weap) : weapon(weap)
{
	name = n;
}

HumanA::~HumanA()
{
	
}

void	HumanA::attack(void)
{
	std::cout	<< name << "attacks with their " 
				<< weapon.getType() << std::endl;
	return ;
}