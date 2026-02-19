#include "Fixed.hpp"

Fixed::Fixed() : value(0) 
{ 
	std::cout << "Default contructor" << std::endl; 
}

Fixed::Fixed(const Fixed &other) 
{
  std::cout << "Copy contructor" << std::endl;
  *this = other;
}

Fixed::Fixed(const float f)
{
	value = roundf(f * (1 << fractionalBits));
}

Fixed::Fixed(const int n)
{
	value = n << fractionalBits;
}

Fixed::~Fixed() 
{
	std::cout << "Destructor"  << std::endl;
}

Fixed&	Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator" << std::endl;
	if (this != &other)
		this->value = other.value;
	return (*this);
}

int	Fixed::getRawBits(void)
{
	return (value);
}

void	Fixed::setRawbits(int const raw)
{
	value = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)value / (1 << fractionalBits));
}

int	Fixed::toInt(void) const
{
	return ((int)value >> fractionalBits);
}
