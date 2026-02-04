/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rardila- <rardila-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 11:34:59 by rardila-          #+#    #+#             */
/*   Updated: 2026/02/03 12:38:39 by rardila-         ###   ########.fr       */
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

std::string	PhoneBook::show_contacts(Contact *cont, int index, int i)
{
	if (i == 0)
		return (std::to_string(cont[index].getIndex()));
	if (i == 1)
		return (cont[index].getFirstName());
	if (i == 2)
		return (cont[index].getLastName()); 
	if (i == 3)
		return (cont[index].getNickName());
	if (i == 4)
		return (cont[index].getPhoneNumber());
	if (i == 5)
		return (cont[index].getDarkestSecret());
	return (void);
}
