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
	std::cout << "\033[33mBefore: \033[0m";
	printVector(_numbers);
	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());
	std::cout << "\033[32mAfter: \033[0m";
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
	if (is_duplicated(_numbers))
	{
		throw (GeneralErrorException("duplicate number"));
	}
}

bool PmergeMe::is_duplicated(std::vector<int> v) const
{
	size_t i = 0;
	size_t j = 0;
	while (i < v.size())
	{
		j = 0;
		while (j < v.size())
		{
			if (i != j)
			{
				if (v[i] == v[j])
					return (true);
			}
			j++;
		}
		i++;
	}
	return (false);
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

// Sort functions

bool	PmergeMe::comparePairs(const std::pair<int, int> &a, const std::pair<int, int> &b)
{
	return (a.second < b.second);
}


std::vector<size_t> PmergeMe::jacobsthalOrder(size_t size)
{
	std::vector<size_t> order;

	if (size == 0)
		return order;

	// b1
	order.push_back(0);

	size_t previous = 1;
	size_t current = 3;

	while (previous < size)
	{
		size_t end = current;
		if (end > size)
			end = size;

		for (size_t i = end; i > previous; --i)
			order.push_back(i - 1);

		size_t next = current + 2 * previous;
		previous = current;
		current = next;
	}

	return order;
}

void PmergeMe::insertPending(std::vector<int>& mainChain, const std::vector<std::pair<int, int> >& pairs)
{
	if (pairs.empty())
		return;

	std::vector<size_t> order = jacobsthalOrder(pairs.size());
	for (std::vector<size_t>::iterator it = order.begin(); it != order.end(); ++it)
	{
		size_t index = *it;
		if (index >= pairs.size())
			continue;
		int small = pairs[index].first;
		int big = pairs[index].second;
		// Buscamos el big asociado
		std::vector<int>::iterator bigPos = std::lower_bound(mainChain.begin(),mainChain.end(), big);
		// El small solamente se busca hasta su big
		std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), bigPos, small);
		mainChain.insert(pos, small);
	}
}


void	PmergeMe::sortVector(std::vector<int> &nums)
{
	if (nums.size() <= 1)
		return ;
	std::vector<std::pair<int, int> >	vectorpairs;
	std::pair<int, int>					p;
	int									straggler = -1;

	// Convertimos el vector nums en parejas con el big y small, si son impares no los guardamos en straggler
	for (size_t i = 1; i < nums.size(); i+= 2)
	{
		int first = nums[i - 1];
		int second = nums[i];
		if (first < second)
			p = std::make_pair(first, second);
		else
		 	p= std::make_pair(second, first);
		vectorpairs.push_back(p);
	}
	// Por si numero impar
	if (nums.size() % 2 != 0)
	{
		straggler = nums.back();
	}
	std::vector<int>	big;
	for (std::vector<std::pair<int, int> >::iterator it = vectorpairs.begin(); it != vectorpairs.end(); ++it)
	{
		big.push_back(it->second);
	}
	sortVector(big);

	std::map<int, std::pair<int, int> > lookup;

	for (size_t i = 0; i < vectorpairs.size(); ++i)
		lookup[vectorpairs[i].second] = vectorpairs[i];

	std::vector<std::pair<int, int> > sortedPairs;
	sortedPairs.reserve(big.size());

	for (size_t i = 0; i < big.size(); ++i)
		sortedPairs.push_back(lookup[big[i]]);

vectorpairs = sortedPairs;

	std::vector<int> mainChain = big;

	insertPending(mainChain, vectorpairs);

	if (straggler != -1)
	{
		std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
		mainChain.insert(pos, straggler);
	}
	nums = mainChain;
}

std::deque<size_t> PmergeMe::jacobsthalOrder_d(size_t size)
{
	std::deque<size_t> order;

	if (size == 0)
		return order;

	// b1
	order.push_back(0);

	size_t previous = 1;
	size_t current = 3;

	while (previous < size)
	{
		size_t end = current;
		if (end > size)
			end = size;

		for (size_t i = end; i > previous; --i)
			order.push_back(i - 1);

		size_t next = current + 2 * previous;
		previous = current;
		current = next;
	}

	return order;
}

void PmergeMe::insertPending_d(std::deque<int>& mainChain,
	const std::deque<std::pair<int, int> >& pairs)
{
	if (pairs.empty())
		return;

	std::deque<size_t> order = jacobsthalOrder_d(pairs.size());

	for (std::deque<size_t>::iterator it = order.begin();
		it != order.end(); ++it)
	{
		size_t index = *it;

		if (index >= pairs.size())
			continue;

		int small = pairs[index].first;
		int big = pairs[index].second;

		// Buscamos el big asociado
		std::deque<int>::iterator bigPos =
			std::lower_bound(mainChain.begin(), mainChain.end(), big);

		// El small solamente se busca hasta su big
		std::deque<int>::iterator pos =
			std::lower_bound(mainChain.begin(), bigPos, small);

		mainChain.insert(pos, small);
	}
}

void PmergeMe::sortDeque(std::deque<int>& nums)
{
	if (nums.size() <= 1)
		return;

	std::deque<std::pair<int, int> > dequepairs;
	std::pair<int, int> p;
	int straggler = -1;

	// Convertimos el deque en parejas con big y small
	for (size_t i = 1; i < nums.size(); i += 2)
	{
		int first = nums[i - 1];
		int second = nums[i];

		if (first < second)
			p = std::make_pair(first, second);
		else
			p = std::make_pair(second, first);

		dequepairs.push_back(p);
	}

	// Por si el numero es impar
	if (nums.size() % 2 != 0)
		straggler = nums.back();

	std::deque<int> big;

	for (std::deque<std::pair<int, int> >::iterator it = dequepairs.begin();
		it != dequepairs.end(); ++it)
	{
		big.push_back(it->second);
	}

	sortDeque(big);

	std::map<int, std::pair<int, int> > lookup;

	for (size_t i = 0; i < dequepairs.size(); ++i)
		lookup[dequepairs[i].second] = dequepairs[i];

	std::deque<std::pair<int, int> > sortedPairs;
	sortedPairs.resize(big.size());

	for (size_t i = 0; i < big.size(); ++i)
		sortedPairs[i] = lookup[big[i]];

	dequepairs = sortedPairs;

	std::deque<int> mainChain = big;

	insertPending_d(mainChain, dequepairs);

	if (straggler != -1)
	{
		std::deque<int>::iterator pos =
			std::lower_bound(mainChain.begin(), mainChain.end(), straggler);

		mainChain.insert(pos, straggler);
	}

	nums = mainChain;
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

