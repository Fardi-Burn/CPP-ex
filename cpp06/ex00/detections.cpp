#include <cctype>
#include <string>
#include <cstdlib>

bool	isChar(const std::string &s)
{
	return (s.length() == 1 && !std::isdigit(s[0]));
}

bool	isInt(const std::string &s)
{
	size_t i = 0;

	if (i == s.length())
		return (false);
	if (s.length() > 11)
		return (false);
	while (i < s.length())
	{
		if (!std::isdigit(s[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	isFloat(const std::string &s)
{
	char	*end;
	
	if (s.empty())
		return (false);
	if (s[s.length() - 1] != 'f')
		return (false);
	std::strtof(s.c_str(), &end);
	return (*end == 'f' && *(end + 1) == '\0');
}

bool	isDouble(const std::string &s)
{
	char *end;
	std::strtod(s.c_str(), &end);
	return (*end == '\0');
}

bool	isPseudo(const std::string &s)
{
	return (s == "nan" ||s == "nanf" || s == "+inf" || s == "-inf" || s == "+inff" || s == "-inff");
}


