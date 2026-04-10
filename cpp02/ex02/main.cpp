/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rardila- <rardila-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 11:01:57 by rardila-          #+#    #+#             */
/*   Updated: 2026/04/10 13:13:28 by rardila-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main (void) 
{
	Fixed		a;
	Fixed const	b(Fixed(5.05f) * Fixed(2));

	std::cout << "++a ,a++" << std::endl;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a++ << std::endl << std::endl;

	std::cout << "--a and a--" << std::endl;
	std::cout << a << std::endl;
	std::cout << --a << std::endl;
	std::cout << a-- << std::endl;
	std::cout << a << std::endl << std::endl;

	std::cout << "Max and minus" << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;
	std::cout << Fixed::min(a, b) << std::endl << std::endl;

	std::cout << "< and >" << std::endl;
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	if (a < b)
		std::cout << "a is smaller than b" << std::endl;
	else
		std::cout << "a is bigger than b" << std::endl;
	if (a > b)
		std::cout << "a is bigger than b" << std::endl;
	else
		std::cout << "a is smaller than b" << std::endl;
	std::cout << "< and >" << std::endl;
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	if (a < b)
		std::cout << "a is smaller than b" << std::endl;
	else
		std::cout << "a is bigger than b" << std::endl;
	if (a > b)
		std::cout << "a is bigger than b" << std::endl;
	else
		std::cout << "a is smaller than b" << std::endl;

	std::cout << "Divs and Mults" << std::endl;
	std::cout << b/a << std::endl;
	std::cout << a*b << std::endl;
	std::cout << "Sums and minus" << std::endl;
	std::cout << a+b << std::endl;
	std::cout << a-b << std::endl;

	return (0);
}
