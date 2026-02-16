/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rardila- <rardila-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 12:00:07 by rardila-          #+#    #+#             */
/*   Updated: 2026/02/16 12:00:09 by rardila-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

void	filter(std::string s1, std::string s2, std::string text, std::string fdin)
{
	std::string	result;
	size_t		pos = 0;
	size_t		found;

	while ((found = text.find(s1, pos)) != std::string::npos)
	{
		result += text.substr(pos, found - pos);
		result += s2;
		pos = found + s1.length();
	}
	result += text.substr(pos);
	std::ofstream	new_file((fdin + ".replace").c_str());
	if (!new_file)
	{
		std::cout	<< "Error making new file" << std::endl;
		return ;
	}
	new_file << result;
	new_file.close();
	return ;
}

int	main(int argc, char	**argv)
{
	if (argc != 4)
	{
		std::cout	<< "Only 3 arguments" << std::endl;
		return (1);
	}
	std::string			fdin = argv[1];
	std::string			s1 = argv[2];
	std::string			s2 = argv[3];
	if (s1.empty())
	{
		std::cout	<< "S1 is empty" << std::endl;
		return (1);
	}
	std::ostringstream	file_text;
	std::ifstream		file(fdin.c_str());
	std::string			text;
	if (!file)
	{
		std::cout	<< "Error opening file" << std::endl;
		return (1);
	}
	file_text << file.rdbuf();
	text = file_text.str();
	filter(s1, s2, text, fdin);
}	
