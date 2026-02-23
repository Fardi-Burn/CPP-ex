/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rardila- <rardila-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 11:02:06 by rardila-          #+#    #+#             */
/*   Updated: 2026/02/19 13:09:24 by rardila-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int					value;
		static const int	fractionalBits = 8;
	public:
		// Constructors
		Fixed();
		Fixed(const int i);
		Fixed(const float f);
		Fixed(const Fixed& other);
		~Fixed();
		// Operators
		Fixed			&operator=(const Fixed& other);
		bool			operator>(const Fixed& other) const;
		bool			operator<(const Fixed& other) const;
		bool			operator>=(const Fixed& other) const;
		bool			operator<=(const Fixed& other) const;
		bool			operator==(const Fixed& other) const;
		bool			operator !=(const Fixed& other) const;
		// Arithmetic Operators
		Fixed			operator+(const Fixed& other) const;
		Fixed			operator-(const Fixed& other) const;
		Fixed			operator*(const Fixed& other) const;
		Fixed			operator/(const Fixed& other) const;
		// Increment and decrement Operators
		Fixed			&operator++();
		Fixed			operator++(int);
		Fixed			&operator--();
		Fixed			operator--(int);
		// Members
		void			setRawbits(int const raw);
		int				getRawBits(void);	
		float			toFloat(void) const;
		int				toInt(void) const;
		static Fixed	&min(Fixed& a, Fixed& b);
		static Fixed	&max(Fixed& a, Fixed& b);
		static const Fixed	&min(const Fixed& a, const Fixed& b);
		static const Fixed	&max(const Fixed& a, const Fixed& b);
};

	std::ostream	&operator<<(std::ostream &os, const Fixed &fixed);

#endif
