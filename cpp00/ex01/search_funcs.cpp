#include "phonebook.hpp"

std::string	characterCap(const std::string &str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

void	printsContactChart(int index, Contact c)
{
	int	i;

	std::cout	<< std::setw(10) << index, "|"
				<< std::setw(10) << characterCap(c.contact[index].)
}
