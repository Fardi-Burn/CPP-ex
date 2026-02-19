/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rardila- <rardila-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 11:02:19 by rardila-          #+#    #+#             */
/*   Updated: 2026/02/19 13:12:03 by rardila-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : value(0) 
{ 
	std::cout << "Default contructor" << std::endl; 
}

Fixed::Fixed(const Fixed &other) 
{
  std::cout << "Copy contructor" << std::endl;
  *this = other;
}

Fixed::Fixed(const float f)
{
	value = roundf(f * (1 << fractionalBits));
}

Fixed::Fixed(const int n)
{
	value = n << fractionalBits;
}

Fixed::~Fixed() 
{
	std::cout << "Destructor"  << std::endl;
}

Fixed	&Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator" << std::endl;
	if (this != &other)
		this->value = other.value;
	return (*this);
}

std::ostream	&operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return (os);
}

int	Fixed::getRawBits(void)
{
	return (value);
}

void	Fixed::setRawbits(int const raw)
{
	value = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)value / (1 << fractionalBits));
}

int	Fixed::toInt(void) const
{
	return ((int)value >> fractionalBits);
}
