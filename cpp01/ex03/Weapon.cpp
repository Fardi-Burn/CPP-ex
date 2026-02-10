/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rardila- <rardila-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 12:01:57 by rardila-          #+#    #+#             */
/*   Updated: 2026/02/10 12:38:43 by rardila-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string name)
{
	setType(name);
}

Weapon::~Weapon()
{
	
}

void	Weapon::setType(std::string t)
{
	type = t;
}

std::string	Weapon::getType(void)
{
	return (type);
}