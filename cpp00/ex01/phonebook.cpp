/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rardila- <rardila-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 11:34:59 by rardila-          #+#    #+#             */
/*   Updated: 2026/02/05 12:40:38 by rardila-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include <string>

PhoneBook::PhoneBook()
{
}

void	PhoneBook::add_contact(std::string first_name, std::string last_name, std::string nickname
				, std::string phone_number, std::string darkest_secret)
{
	static int	i = 0;

	if (i == 8)
		i = 0;
	contacts[i].setFirstName(first_name);
	contacts[i].setLastName(last_name);
	contacts[i].setNickName(nickname);
	contacts[i].setPhoneNumber(phone_number);
	contacts[i].setDarkestSecret(darkest_secret);
	contacts[i].setIndex(i + 1);
	i++;
	return ;
}

Contact	*PhoneBook::get_contacts()
{
	return (contacts);
}

void	PhoneBook::printsContactChart(int cont, Contact *c)
{
	int	i;
	
	i = 0;
	std::cout << std::setw(10) << "INDEX" << "|"
				<< std::setw(10) << "FIRST NAME" << "|"
				<< std::setw(10) << "LAST NAME" << "|"
				<< std::setw(10) << "NICKNAME" << "|" << std::endl;
	while (i < cont)
	{
		std::cout	<< std::setw(10) << (i + 1) << "|"
					<< std::setw(10) << characterCap(c[i].getFirstName()) << "|"
					<< std::setw(10) << characterCap(c[i].getLastName()) << "|"
					<< std::setw(10) << characterCap(c[i].getNickName()) << "|" << std::endl;
		i++;
	}
}

void	PhoneBook::printContact(std::string index, Contact *c, int cont)
{
	int i;

	if (index.length() > 1)
	{
		std::cout << "Out of range" << std::endl;
		return ;
	}
	i = std::stoi(index);
	if (i < 1 || i > cont)
	{
		std::cout << "Out of range" << std::endl;
		return ;
	}
	std::cout	<< "First Name: " << c[i - 1].getFirstName() << std::endl
				<< "Last Name: " << c[i - 1].getLastName() << std::endl
				<< "Nick-Name: " << c[i - 1].getNickName() << std::endl
				<< "Phone Number: " << c[i - 1].getPhoneNumber() << std::endl
				<< "Darkest Secret: " << c[i - 1].getDarkestSecret() << std::endl;
	return ;
}
