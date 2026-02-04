/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rardila- <rardila-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 11:35:23 by rardila-          #+#    #+#             */
/*   Updated: 2026/02/03 13:11:39 by rardila-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

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
		if (!isascii(str[i]))
		{
			std::cout << "Only ascii characteres!!!\n";
			return (1);
		}
	}
	return (0);
}

void	add_questions(PhoneBook *pb)
{
	std::string	f_name;
	std::string	l_name;
	std::string	nick_n;
	std::string	phone_n;
	std::string	darkest;

	while (isascii_and_notempty(f_name) == 1)
	{
		std::cout << "First Name: ";
		std::getline(std::cin, f_name);
	}
	while (isascii_and_notempty(l_name) == 1)
	{
		std::cout << "Last Name: ";
		std::getline(std::cin, l_name);
	}
	while (isascii_and_notempty(nick_n) == 1)
	{
		std::cout << "NickName: ";
		std::getline(std::cin, nick_n);
	}
	while (isascii_and_notempty(phone_n) == 1 || only_nums(phone_n) == 1)
	{
		std::cout << "Phone Number: ";
		std::getline(std::cin, phone_n);
	}
	while (isascii_and_notempty(darkest) == 1)
	{
		std::cout << "Darkest Secret: ";
		std::getline(std::cin, darkest);
	}
	pb->add_contact(f_name, l_name, nick_n, phone_n, darkest);
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

int			valid_name(std::string str)
{
	str = to_upper(str);
	if (str == "ADD")
		return (1);
	if (str == "SEARCH")
		return (2);
	if (str == "EXIT")
		return (3);
	return (0);
}



int		main(void)
{
	PhoneBook pb;
	std::string input;

	while (1)
	{
		std::cout << "ADD, SEARCH OR EXIT: ";
		std::getline(std::cin, input);
		if (valid_name(input) != 0)
		{
			if (valid_name(input) == 1)
				add_questions(&pb);
			if (valid_name(input) == 2)
			{
				//search_contact();
			}
			if (valid_name(input) == 3)
			{
				return (0);
			}
		}
	}
	return (0);
}
