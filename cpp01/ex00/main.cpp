/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rardila- <rardila-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 11:28:46 by rardila-          #+#    #+#             */
/*   Updated: 2026/02/10 11:28:47 by rardila-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <string>
#include <iostream>

int	main(void)
{
	Zombie		*nothuman;
	std::string	input;

	std::cout 	<< "First Zombie name using newZombie" << std::endl;
	std::getline(std::cin, input);
	nothuman = newZombie(input);
	nothuman->announce();
	delete nothuman;
	std::cout 	<< std::endl << "Second Zombie name using randomChump" << std::endl 
				<< "(deletes at the end of funcion)" << std::endl;
	std::getline(std::cin, input);
	randomChump(input);
	return (0);
}
