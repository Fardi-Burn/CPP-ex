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

/*
Form	&Form::operator=(const Form &other)
{
	if (this != &other)
	{
		_name = other._name;
		_signed = other._signed;
		_req_sign = other._req_sign;
		_req_execute = other._req_execute;
	}
	return (*this);
}*/

Form::~Form()
{

}

// Getters

const std::string	Form::getName()
{
	return (_name);
}

const bool	Form::getSigned()
{
	return (_signed);
}

const int	Form::getReq_sign()
{
	return (_req_sign);
}

const int	Form::getReq_execute()
{
	return (_req_execute);
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

