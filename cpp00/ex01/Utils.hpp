/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rardila- <rardila-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 11:04:35 by rardila-          #+#    #+#             */
/*   Updated: 2026/02/05 12:49:29 by rardila-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# include <string>

std::string characterCap(const std::string &str);
std::string	to_upper(std::string str);
int		only_nums(std::string str);
int		isascii_and_notempty(std::string str);

#endif