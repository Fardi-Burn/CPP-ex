/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rardila- <rardila-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 11:58:08 by rardila-          #+#    #+#             */
/*   Updated: 2026/02/10 12:39:09 by rardila-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <string>

class Weapon
{
	private:
		std::string	type;
	public:
		Weapon(std::string name);
		~Weapon();
		void		setType(std::string t);
		std::string	getType(void);
};

#endif