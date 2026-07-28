#pragma once
#include <algorithm>
# include <exception>

class NoCoincidenceException : public std::exception
{
	public:
		const char *what() const throw()
		{
			return ("Value not found");
		}
};

template <typename T>
typename T::iterator	easyfind(T &array, int number)
{
	typename T::iterator it;

	it = std::find(array.begin(), array.end(), number);
	if (it == array.end())	
		throw (NoCoincidenceException());
	return (it);
}
