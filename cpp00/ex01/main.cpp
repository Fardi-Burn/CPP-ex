/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rardila- <rardila-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 11:35:23 by rardila-          #+#    #+#             */
/*   Updated: 2026/02/05 12:35:50 by rardila-         ###   ########.fr       */
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
		if (!isalnum(str[i]))
		{
			std::cout << "Only numbers and alpha characteres!!!\n";
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
	
	std::cout << "First Name: ";
	while (std::getline(std::cin, f_name) && isascii_and_notempty(f_name) == 1)
	{
		std::cout << "First Name: ";
	}
	std::cout << "Last Name: ";
	while (std::getline(std::cin, l_name) && isascii_and_notempty(l_name) == 1)
	{
		std::cout << "Last Name: ";
	}
	std::cout << "NickName: ";
	while (std::getline(std::cin, nick_n) && isascii_and_notempty(nick_n) == 1)
	{
		std::cout << "NickName: ";
	}
	std::cout << "Phone Number: ";
	while (std::getline(std::cin, phone_n) && (isascii_and_notempty(phone_n) == 1 || only_nums(phone_n) == 1))
	{
		std::cout << "Phone Number: ";
	}
	std::cout << "Darkest Secret: ";
	while (std::getline(std::cin, darkest) && isascii_and_notempty(darkest) == 1)
	{
		std::cout << "Darkest Secret: ";
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
	PhoneBook	pb;
	std::string	input;
	int			cont;

	cont = 0;
	while (1)
	{
		if (cont > 8)
		cont = 8;
		std::cout << "ADD, SEARCH OR EXIT: ";
		if (!std::getline(std::cin, input))
			break ;
		if (valid_name(input) != 0)
		{
			if (valid_name(input) == 1)
			{
				add_questions(&pb);
				cont++;
			}
			if (valid_name(input) == 2)
			{
				pb.printsContactChart(cont, pb.get_contacts());
				std::cout << "Put index:";
				std::getline(std::cin, input);
				pb.printContact(input, pb.get_contacts(), cont);
			}
			if (valid_name(input) == 3)
			{
				return (0);
			}
		}
	}
	return (0);
}
