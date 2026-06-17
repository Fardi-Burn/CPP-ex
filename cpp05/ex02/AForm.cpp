#include "AForm.hpp"

AForm::AForm() : _name("default"), _signed(0), _req_sign(150), _req_execute(150)
{
	
}

AForm::AForm(std::string name, int req_sign, int req_excecute) : _name(name), _signed(0), _req_sign(req_sign), _req_execute(req_excecute)
{
	if (_req_sign < 1 || _req_execute < 1)
		throw (GradeTooHighException());
	if (_req_sign > 150 || _req_execute > 150)
		throw (GradeTooLowException());
}

AForm::AForm(const AForm &other) : _name(other._name), _signed(0), _req_sign(other._req_sign), _req_execute(other._req_execute)
{

}


AForm	&AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		_req_sign = other._req_sign;
		_req_execute = other._req_execute;
	}
	return (*this);
}

AForm::~AForm()
{

}

// Getters

std::string	AForm::getName() const
{
	return (_name);
}

bool	AForm::getSigned() const
{
	return (_signed);
}

int	AForm::getReq_sign() const
{
	return (_req_sign);
}

int	AForm::getReq_execute() const
{
	return (_req_execute);
}
// Member functions

void	AForm::beSigned(Bureaucrat &bureau)
{
	if (bureau.getGrade() > _req_sign)
		throw (GradeTooLowException());
	if (_signed == 1)
		throw (AlreadySignedException());
	if (_signed == 0)
		_signed = 1;
}

// Exceptions

const char	*AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

const char	*AForm::AlreadySignedException::what() const throw()
{
	return ("Form is already sign");
}

std::ostream& operator<<(std::ostream &os, const AForm &form)
{
	std::string	state;

	if (form.getSigned() == 1)
		state = "signed";
	else
		state = "not signed";
	os << form.getName() << " is " << state << ", the grade for signing it is " 
		<< form.getReq_sign() << " and the grade for executing it is " << form.getReq_execute();

	return (os);
}

