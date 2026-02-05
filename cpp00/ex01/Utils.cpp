/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_funcs.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rardila- <rardila-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 11:04:38 by rardila-          #+#    #+#             */
/*   Updated: 2026/02/05 11:04:39 by rardila-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

std::string	characterCap(const std::string &str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}
