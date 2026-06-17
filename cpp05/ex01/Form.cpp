#include "Form.hpp"

Form::Form() : _name("default"), _signed(0), _req_sign(150), _req_execute(150)
{
	
}

Form::Form(std::string name, int req_sign, int req_excecute) : _name(name), _signed(0), _req_sign(req_sign), _req_execute(req_excecute)
{
	if (_req_sign < 1 || _req_execute < 1)
		throw (GradeTooHighException());
	if (_req_sign > 150 || _req_execute > 150)
		throw (GradeTooLowException());
}

Form::Form(const Form &other) : _name(other._name), _signed(0), _req_sign(other._req_sign), _req_execute(other._req_execute)
{

}


Form	&Form::operator=(const Form &other)
{
	if (this != &other)
	{
		_req_sign = other._req_sign;
		_req_execute = other._req_execute;
	}
	return (*this);
}

Form::~Form()
{

}

// Getters

std::string	Form::getName() const
{
	return (_name);
}

bool	Form::getSigned() const
{
	return (_signed);
}

int	Form::getReq_sign() const
{
	return (_req_sign);
}

int	Form::getReq_execute() const
{
	return (_req_execute);
}
// Member functions

void	Form::beSigned(Bureaucrat &bureau)
{
	if (bureau.getGrade() > _req_sign)
		throw (GradeTooLowException());
	if (_signed == 1)
		throw (AlreadySignedException());
	if (_signed == 0)
		_signed = 1;
}

// Exceptions

const char	*Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

const char	*Form::AlreadySignedException::what() const throw()
{
	return ("Form is already sign");
}

std::ostream& operator<<(std::ostream &os, const Form &form)
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

