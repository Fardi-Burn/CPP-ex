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

////////////////////////////////////////////////////////////////

// Constructors

Fixed::Fixed() : value(0) 
{ 
	//std::cout << "Default contructor" << std::endl; 
}

Fixed::Fixed(const Fixed &other) 
{
  //std::cout << "Copy contructor" << std::endl;
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
	//std::cout << "Destructor"  << std::endl;
}

////////////////////////////////////////////////////////////////

// Member functions

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

Fixed	&Fixed::min(Fixed& a, Fixed& b)
{
	if (a.value < b.value)
		return (a);
	else
	return (b);
}

Fixed	&Fixed::max(Fixed& a, Fixed& b)
{
	if (a.value > b.value)
		return (a);
	else
	 return (b);
}

const Fixed	&Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a.value < b.value)
		return (a);
	else
	 return (b);
}

const Fixed	&Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a.value > b.value)
		return (a);
	else
	 return (b);
}

////////////////////////////////////////////////////////////////

// Operators

Fixed	&Fixed::operator=(const Fixed &other)
{
	//std::cout << "Copy assignment operator" << std::endl;
	if (this != &other)
		this->value = other.value;
	return (*this);
}

std::ostream	&operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return (os);
}

bool	Fixed::operator>(const Fixed& other) const
{
	return (this->value > other.value);
}

bool	Fixed::operator<(const Fixed& other) const
{
	return (this->value < other.value);
}

bool	Fixed::operator>=(const Fixed& other) const
{
	return (this->value >= other.value);
}

bool	Fixed::operator<=(const Fixed& other) const
{
	return (this->value <= other.value);
}

bool	Fixed::operator==(const Fixed& other) const
{
	return (this->value == other.value);
}

bool	Fixed::operator!=(const Fixed& other) const
{
	return (this->value != other.value);
}

////////////////////////////////////////////////////////////////

// Arithmetic Operator

Fixed	Fixed::operator+(const Fixed& other) const
{
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed	Fixed::operator-(const Fixed& other) const
{
	return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed	Fixed::operator*(const Fixed& other) const
{
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed	Fixed::operator/(const Fixed& other) const
{
	return (Fixed(this->toFloat() / other.toFloat()));
}

////////////////////////////////////////////////////////////////

// Increment and decrement Operators

Fixed	&Fixed::operator++()
{
	this->value++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed temp(*this);
	this->value++;
	return (temp);
}

Fixed	&Fixed::operator--()
{
	this->value--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed temp(*this);
	this->value--;
	return (temp);
}

////////////////////////////////////////////////////////////////
