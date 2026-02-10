/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rardila- <rardila-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 11:30:22 by rardila-          #+#    #+#             */
/*   Updated: 2026/02/10 11:43:43 by rardila-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie	*nothumans;

	if (N < 1)
		N = 0;
	nothumans = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		nothumans[i].set_name(name);
	}
	return (nothumans);
}