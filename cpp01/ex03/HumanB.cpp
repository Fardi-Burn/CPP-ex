/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rardila- <rardila-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 12:29:19 by rardila-          #+#    #+#             */
/*   Updated: 2026/02/10 12:48:34 by rardila-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string n)
{
	name = n;
}

HumanB::~HumanB()
{
	
}

void	HumanB::setWeapon(Weapon &weap)
{
	weapon = &weap;
}

void	HumanB::attack(void)
{
	std::cout	<< name << " attacks with their " 
				<< weapon->getType() << std::endl;
}