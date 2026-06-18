#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{

}

RobotomyRequestForm::~RobotomyRequestForm()
{

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
