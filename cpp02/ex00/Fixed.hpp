/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rardila- <rardila-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 11:02:36 by rardila-          #+#    #+#             */
/*   Updated: 2026/02/19 11:02:37 by rardila-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed 
{
	private:
		int					value;
		static const int	fractionalBits = 8;
	public:
		Fixed();
		Fixed(const Fixed& other);
		~Fixed();
		Fixed&	operator=(const Fixed& other);
		int		getRawBits(void);
		void	setRawbits(int const raw);
};

#endif
