#pragma once

# include <string>
# include "AForm.hpp"

class Aform;

class Intern
{
	public:
		Intern();
		Intern(const Intern &other);
		~Intern();
		Intern	&operator=(const Intern &other);
		AForm	*makeForm(const std::string name, const std::string target);
};
