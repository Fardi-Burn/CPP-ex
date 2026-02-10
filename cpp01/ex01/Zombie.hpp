/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rardila- <rardila-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 11:28:30 by rardila-          #+#    #+#             */
/*   Updated: 2026/02/10 11:33:59 by rardila-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>
# include <string>

class	Zombie
{
	private:
		std::string	name;
	public:
		Zombie(void);
		~Zombie();
		void	set_name(std::string name);
		void	announce(void);
};

Zombie	*zombieHorde(int N, std::string name);

#endif
