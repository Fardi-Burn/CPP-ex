#pragma once

# include <string>
# include <limits>

# define MIN_INT std::numeric_limits<int>::min() //-2147483648
# define MAX_INT std::numeric_limits<int>::max() //2147483647
# define MIN_FLOAT std::numeric_limits<float>::min() //-3.40282e+38
# define MAX_FLOAT std::numeric_limits<float>::max() //3.40282e+38
# define MIN_DOUBLE std::numeric_limits<double>::min() //-1.79769e+308
# define MAX_DOUBLE std::numeric_limits<double>::max() //1.79769e+308

class ScalarConverter
{
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter &operator=(const ScalarConverter &other);
		ScalarConverter(const ScalarConverter &other);
	public:
	static void	convert(const std::string &str);
};


bool	isChar(const std::string &s);
bool	isInt(const std::string &s);
bool	isFloat(const std::string &s);
bool	isDouble(const std::string &s);
bool	isPseudo(const std::string &s);
