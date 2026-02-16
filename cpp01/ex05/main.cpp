/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rardila- <rardila-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 11:12:17 by rardila-          #+#    #+#             */
/*   Updated: 2026/02/16 11:58:16 by rardila-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	Harl	h;
	
	std::cout << "##### MESSAGES #####" << std::endl << std::endl;
	std::cout << "##### DEBUG MESSAGE #####" << std::endl;
	h.complain("DEBUG");
	std::cout << "##### INFO MESSAGE #####" << std::endl;
	h.complain("INFO");
	std::cout << "##### WARNING MESSAGE #####" << std::endl;
	h.complain("WARNING");
	std::cout << "##### ERROR MESSAGE #####" << std::endl;
	h.complain("ERROR");
	return (0);
}