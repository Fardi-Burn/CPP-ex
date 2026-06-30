#include "ScalarConverter.hpp"
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>

static void	printChar(double value)
{
	if (std::isnan(value) || value < 0 || value > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(static_cast<char>(value)))
		std::cout << "char: Non displayable" << std::endl;
	else
	{
		std::cout << "char: " << static_cast<char>(value) << std::endl;
	}
}

static void	printInt(double value)
{
	if (std::isnan(value) || value > MAX_INT || value < MIN_INT)
		std::cout << "int: impossible" << std::endl;
	else
	{
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	}
}

static void	printFloat(double value, std::string str)
{
	size_t	dot = str.find('.');
	int		decimals = 1;

	if (dot != std::string::npos)
	{
		size_t	i = dot + 1;
		while (i < str.length() && std::isdigit(str[i]))
			i++;
		decimals = i - dot - 1;
	}
	if (decimals > 7)
		decimals = 7;
	std::cout << "float: " << std::fixed << std::setprecision(value == static_cast<int>(value) ? 1 : decimals) << static_cast<float>(value) << "f" << std::endl;
}

static void	printDouble(double value, std::string str)
{
	size_t	dot = str.find('.');
	int		decimals = 1;

	if (dot != std::string::npos)
	{
		size_t	i = dot + 1;
		while (i < str.length() && std::isdigit(str[i]))
			i++;
		decimals = i - dot - 1;
	}
	if (decimals > 17)
		decimals = 17;
	std::cout << "double: " << std::fixed << std::setprecision(value == static_cast<int>(value) ? 1 : decimals) << value << std::endl;
}


void	ScalarConverter::convert(const std::string &str)
{
	double	value;
	bool	converted = 0;

	if (isChar(str) && converted == 0)
	{
		 value = static_cast<double>(str[0]);
		 converted = 1;
	}
	if (isInt(str) && converted == 0)
	{
		value = static_cast<double>(std::atoi(str.c_str()));
		 converted = 1;
	}
	if (isFloat(str) && converted == 0)
	{
		value = static_cast<double>(strtof(str.c_str(), NULL));
		 converted = 1;
	}
	if (isDouble(str) && converted == 0)
	{
		value = std::strtod(str.c_str(), NULL);
		 converted = 1;
	}
	if (converted == 0)
	{
		std::cout << "Incorrect input" << std::endl;
		return ;
	}
	printChar(value);
	printInt(value);
	printFloat(value, str);
	printDouble(value, str);
	// std::cout << "DEBUG value = " << value << std::endl;
	return ;
}
