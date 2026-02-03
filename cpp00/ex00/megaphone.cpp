/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rardila- <rardila-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 13:08:34 by rardila-          #+#    #+#             */
/*   Updated: 2026/01/29 13:35:30 by rardila-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	int		i;

	i = 1;
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEREABLE FEEDBACK NOISE *\n";
		return (0);
	}
	while (argv[i])
	{
		for(int j = 0; argv[i][j]; j++)
			std::cout << (char)std::toupper(argv[i][j]);
		i++;
	}
	std::cout << '\n';
	return (0);
}