#include "Intern.hpp"
#include <iostream>
#include "forms/PresidentialPardonForm.hpp"
#include "forms/RobotomyRequestForm.hpp"
#include "forms/ShrubberyCreationForm.hpp"

Intern::Intern()
{

}

Intern::Intern(const Intern &other)
{
	*this = other;
}

Intern	&Intern::operator=(const Intern &other)
{
	(void)other;
	return (*this);
}

Intern::~Intern()
{

}


AForm	*Intern::makeForm(const std::string name, const std::string target)
{
	std::string n_forms[] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};

	int i = 0;
	while (i < 3 && name != n_forms[i])
		i++;
	switch (i)
	{
		case 0:
			std::cout << "Intern creates " << name << std::endl;
			return (new ShrubberyCreationForm(target));
		case 1:
			std::cout << "Intern creates " << name << std::endl;
			return (new RobotomyRequestForm(target));
		case 2:
			std::cout << "Intern creates " << name << std::endl;
			return (new PresidentialPardonForm(target));
		default:
			std::cout << "Form doesn't exist" << std::endl;
			return (NULL);
	}
}
