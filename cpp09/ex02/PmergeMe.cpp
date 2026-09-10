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
		long value = std::atol(_raw_argv[j]);
		if (value < 1 || value > INT_MAX)
				throw (ArgumentsErrorException(_raw_argv[j]));
		_numbers.push_back(static_cast<int>(value));
		j++;
	}
	_vec = _numbers;
	std::deque<int>	deq(_vec.begin(), _vec.end());
	_deq = deq;
}

void PmergeMe::printVector(const std::vector<int>& numbers)
{
	for (std::vector<int>::const_iterator it = numbers.begin();
		it != numbers.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}
void PmergeMe::before_after_print()
{
	std::cout << "Before: ";
	printVector(_numbers);
	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());
	std::cout << "After: ";
	printVector(sorted);
}

void	PmergeMe::special_cases()
{
	if (_numbers.size() == 1)
		throw (GeneralErrorException("only 1 number"));
	if (is_sorted(_numbers))
	{
		throw (GeneralErrorException("already sorted"));
	}
}

bool PmergeMe::is_sorted(std::vector<int> v) const
{
    for (size_t i = 1; i < _numbers.size(); ++i)
    {
        if (v[i] < v[i - 1])
            return (false);
    }
    return (true);
}


// ArgumentsErrorException

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

// GeneralErrorException

PmergeMe::GeneralErrorException::GeneralErrorException(const std::string &argument)
{
	_message = "Error: " + argument;
}

const char	*PmergeMe::GeneralErrorException::what() const throw()
{
	return (_message.c_str());
}

PmergeMe::GeneralErrorException::~GeneralErrorException() throw()
{
}

