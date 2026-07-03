#pragma once

#include <exception>
template <typename T>
class	Array
{
	private:
		T*				_array;
		unsigned int	_size; 
	public:
		Array();
		Array(unsigned int size);
		~Array();
		Array(const Array &other);
		Array	&operator=(const Array &other);
		T		&operator[](unsigned int index);
		const T		&operator[](unsigned int index) const;
		unsigned int	size();
		class	OutOfBoundsException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Index out of bounds");
				}
		};
};

#include "Array.tpp"
