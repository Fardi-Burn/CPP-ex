#include "ShrubberyCreationForm.hpp"
#include <fstream>

// Constructor

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{

}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

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
