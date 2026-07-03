#include "Array.hpp"
#include <cstdlib>

template <typename T>
Array<T>::Array() : _array(NULL), _size(0)
{
	
}

template <typename T>
Array<T>::Array(unsigned int size) : _array(NULL), _size(size)
{
	_array = new T[size];
}

template <typename T>
Array<T>::~Array()
{
	delete[] _array;
}

template <typename T>
Array<T>::Array(const Array<T> &other) : _size(other._size)
{
	if (_size == 0)
	{
		_array = NULL;
		return ;
	}
	_array = new T[_size];
	for (unsigned int i = 0; i < _size; i++)
	{
		_array[i] = other._array[i];
	}
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
	if (this == &other)
		return (*this);
	delete[] _array;

	_size = other._size;

	if (_size == 0)
	{
		_array = NULL;
		return (*this);
	}

	_array = new T[_size];
	for (unsigned int i = 0; i < _size; i++)
		_array[i] = other._array[i];
	return (*this);
}

template <typename T>
T	&Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw (OutOfBoundsException());
	return (_array[index]);
}

template <typename T>
const T	&Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)
		throw (OutOfBoundsException());
	return (_array[index]);
}

template <typename T>
unsigned int	Array<T>::size()
{
	return (_size);
}
