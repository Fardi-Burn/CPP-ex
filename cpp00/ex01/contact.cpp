/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rardila- <rardila-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 11:35:09 by rardila-          #+#    #+#             */
/*   Updated: 2026/02/03 12:40:24 by rardila-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

Contact::Contact() 
{
	first_name = "";
	last_name = "";
	nickname = "";
	phone_number = "";
	darkest_secret = "";
}

// First Name

std::string	Contact::getFirstName(void) const
{
	return (first_name);
}

void	Contact::setFirstName(std::string first_name)
{
	this->first_name = first_name;
}

// Last Name

std::string	Contact::getLastName(void) const
{
	return (last_name);
}

void	Contact::setLastName(std::string last_name)
{
	this->last_name = last_name;
}

// NickName

std::string	Contact::getNickName(void) const
{
	return (nickname);
}

void	Contact::setNickName(std::string nickname)
{
	this->nickname = nickname;
}

// Phone Number

std::string	Contact::getPhoneNumber(void) const
{
	return (phone_number);
}

void	Contact::setPhoneNumber(std::string phone_number)
{
	this->phone_number = phone_number;
}

// Darkest Secret

std::string	Contact::getDarkestSecret(void) const
{
	return (darkest_secret);
}

void	Contact::setDarkestSecret(std::string darkest_secret)
{
	this->darkest_secret = darkest_secret;
}

// Index

int	Contact::getIndex(void) const
{
	return (index);
}

void	Contact::setIndex(int index)
{
	this->index = index;
}