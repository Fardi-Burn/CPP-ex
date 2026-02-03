/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rardila- <rardila-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 11:35:02 by rardila-          #+#    #+#             */
/*   Updated: 2026/02/03 12:28:51 by rardila-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H
# include "contact.hpp"
# include <string>
# include <iostream>

class PhoneBook 
{
	private:
		Contact contacts[8];
	public:
		// Constructor
		PhoneBook();
		Contact	*get_contacts();
		void	show_contacts(Contact *cont);
		void	add_contact(std::string first_name, std::string last_name, std::string nickname
							, std::string phone_number, std::string darkest_secret);
};

#endif
