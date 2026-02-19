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
		Fixed();
		Fixed(const int i);
		Fixed(const float f);
		Fixed(const Fixed& other);
		~Fixed();
		Fixed			&operator=(const Fixed& other);
		int				getRawBits(void);
		void			setRawbits(int const raw);
		float			toFloat(void) const;
		int				toInt(void) const;
};

	std::ostream	&operator<<(std::ostream &os, const Fixed &fixed);

#endif
