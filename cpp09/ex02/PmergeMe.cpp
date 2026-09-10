#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _raw_argv(NULL)
{
	throw (ArgumentsErrorException(_raw_argv[1]));
}

PmergeMe::PmergeMe(char **argv) : _raw_argv(argv)
{

}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	if (this != &other)
		*this = other;
}

PmergeMe PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
		return (*this);
	return (*this);
}

PmergeMe::~PmergeMe()
{

}

// Members

void	PmergeMe::correct_argv()
{
	int	j = 1;
	int i = 0;
	while (_raw_argv[j])
	{
		i = 0;
		if (_raw_argv[j][0] == '\0')
				throw (ArgumentsErrorException(_raw_argv[j]));
		while (_raw_argv[j][i])
		{
			if (!std::isdigit(_raw_argv[j][i]))
				throw (ArgumentsErrorException(_raw_argv[j]));
			if (i >= 10)
				throw (ArgumentsErrorException(_raw_argv[j]));
			i++;
		}
		if (std::atol(_raw_argv[j]) < 1
				|| std::atol(_raw_argv[j]) > INT_MAX)
				throw (ArgumentsErrorException(_raw_argv[j]));
		j++;
	}
}

// Execptions

PmergeMe::ArgumentsErrorException::ArgumentsErrorException(const std::string &argument)
{
	_message = "Invalid argument: " + argument;
}

const char	*PmergeMe::ArgumentsErrorException::what() const throw()
{
	return (_message.c_str());
}

PmergeMe::ArgumentsErrorException::~ArgumentsErrorException() throw()
{
}

