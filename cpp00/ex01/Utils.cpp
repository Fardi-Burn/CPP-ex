/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rardila- <rardila-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 11:04:38 by rardila-          #+#    #+#             */
/*   Updated: 2026/02/05 12:48:55 by rardila-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

std::string	characterCap(const std::string &str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

std::string	to_upper(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] >= 97 && str[i] <= 122)
		{
			str[i] = str[i] - 32;
		}
	}
	return (str);
}

int		only_nums(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
		{
			std::cout << "Only numbers!!!\n";
			return (1);
		}
	}
	return (0);
}

int		isascii_and_notempty(std::string str)
{
	if (str.empty() == 1)
	{
		return (1);
	}
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!isalnum(str[i]))
		{
			std::cout << "Only numbers and alpha characteres!!!\n";
			return (1);
		}
	}
	return (0);
}
