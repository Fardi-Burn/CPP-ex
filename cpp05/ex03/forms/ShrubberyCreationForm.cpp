#include "ShrubberyCreationForm.hpp"
#include <fstream>

// Constructor

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default")
{

}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{

}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other)
{
	*this = other;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	_target = other._target;
	return (*this);
}

void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	checkExecution(executor);

	std::ofstream file((_target + "_shrubbery").c_str());

file <<
"       &&& &&  & &&\n"
"      && &/&|& ()|/ @, &&\n"
"     &/(/&/&||/& /_/)_&/_&\n"
"  &() &/&|()|/&/ '% & ()\n"
" &_\\_&&_\\ |& |&&/&__%_/_& &&\n"
"&&   && & &| &| /& & % ()& /&&\n"
"()&_---()&\\&|&&-&&--%---()~\n"
"    &&     |||\n"
"            |||\n"
"            |||\n"
"            |||\n"
"      , -=-~  .-^- _\n";
}
