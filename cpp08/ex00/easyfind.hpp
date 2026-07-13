#pragma once
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

	for (it = array.begin(); it != array.end(); ++it)
	{
		if (*it == number)
			return (it);
	}
	throw (NoCoincidenceException());
}
