#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default")
{

}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{

}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other)
{
	*this = other;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	_target = other._target;
	return (*this);
}


void	RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	checkExecution(executor);

	std::cout << "Rrrrrrrrrrrh" << std::endl;

	if (std::rand() % 2 == 0)
		std::cout << _target << " has been robotomized!" << std::endl;
	else
	 	std::cout << _target << " hasn't been robotomized" << std::endl;
}
