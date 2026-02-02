#include <iostream>
#include "phonebook.hpp"

int	valid_name(std::string string)
{
	if (string == "ADD")
		return (1);
	if (string == "SEARCH")
		return (2);
	if (string == "EXIT")
		return (3);
	return (0);
}

int	main(void)
{
	std::string input;

	std::cout << "ADD, SEARCH OR EXIT\n";
	while (1)
	{
		std::getline(std::cin, input);
		std::cout << "Has escrito: " << input << std::endl;
		if (valid_name(input) != 0)
		{
			if (valid_name(input) == 1)
				add_contact();
			if (valid_name(input) == 2)
				search_contact();
			if (valid_name(input) == 3)
				return (0);
			
		}
	}
	return (0);
}
