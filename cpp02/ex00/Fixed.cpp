/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rardila- <rardila-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 11:02:31 by rardila-          #+#    #+#             */
/*   Updated: 2026/02/19 11:02:32 by rardila-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <ostream>

Fixed::Fixed() : value(0) 
{ 
	std::cout << "Default contructor" << std::endl; 
}

Fixed::Fixed(const Fixed &other) 
{
  std::cout << "Copy contructor" << std::endl;
  *this = other;
}

Fixed::~Fixed() 
{
	std::cout << "Destructor"  << std::endl;
}

Fixed&	Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator" << std::endl;
	if (this != &other)
		this->value = other.value;
	return (*this);
}

int	Fixed::getRawBits(void)
{
	return (value);
}

void	Fixed::setRawbits(int const raw)
{
	value = raw;
}
