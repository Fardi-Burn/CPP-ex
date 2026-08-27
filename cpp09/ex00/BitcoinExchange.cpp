#include "BitcoinExchange.hpp"

btc::btc()
{
}

btc::btc(btc const &other)
{
	if (this != &other)
		*this = other;
}

btc &btc::operator=(btc const &other)
{
	if (this != &other)
		_Data_Base = other._Data_Base;
	return (*this);
}

btc::~btc()
{
}


void	btc::table_parser(std::string name_file)
{
	std::ifstream		data_base("data.csv");
	std::ifstream		file(name_file.c_str());
	std::stringstream	line;
	
	// Comprobar que se abran los archivos
	if (!data_base.is_open())
		throw (ErrorOpenigFileException());
	if (!file.is_open())
		throw (ErrorOpenigFileException());
	// Hacer mapa de la data_base
	if (!this->map_maker(data_base))
		throw (std::runtime_error("Error in data base format"));
	file.close();
	data_base.close();
}

int btc::isValidDate(int year, int month, int day)
{
    if (year < 1 || month < 1 || month > 12 || day < 1)
        return (0);
    int daysInMonth[] = {
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };
    if (month == 2 &&
        (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)))
    {
        daysInMonth[1] = 29;
    }
    if (day > daysInMonth[month - 1])
        return (0);
    return (1);
}


int	btc::correct_format_table(std::string line)
{
	if (line.size() < 12)
		return (0);
	for (int i = 0; i < 4; i++)
	{
		if (!std::isdigit(line[i]))
			return (0);
	}
	if (line[4] != '-')
		return (0);
	for (int i = 5; i < 7; i++)
	{	
		if (!std::isdigit(line[i]))
			return (0);
	}
	if (line[7] != '-')
		return (0);
	for (int i = 8; i < 10; i++)
	{	
		if (!std::isdigit(line[i]))
			return (0);
	}
	if (line[10] != ',')
		return (0);
	int year = (line[0] - '0') * 1000
             + (line[1] - '0') * 100
             + (line[2] - '0') * 10
             + (line[3] - '0');

    int month = (line[5] - '0') * 10
              + (line[6] - '0');

    int day = (line[8] - '0') * 10
            + (line[9] - '0');
	if (!isValidDate(year, month, day))
		return (0);
	std::string priceStr = line.substr(11);
	char *end;
	strtod(priceStr.c_str(), &end);
	if (*end != '\0')
		return (0);
	return (1);
}

int	btc::map_maker(std::ifstream &data_base)
{
	std::string	line;
	std::string	date;
	std::string	priceStr;
	size_t		comma;
	double		price;
	
	if (!std::getline(data_base, line))
		return (0);
	if (line != "date,exchange_rate")
		return (0);
	while(std::getline(data_base, line))
	{
		if (!this->correct_format_table(line))
			return (0);
		comma = line.find(',');
		date = line.substr(0, comma);
		char *end;
		price = strtod(line.substr(comma + 1).c_str(), &end);
		_Data_Base[date] = price;
	}

	return (1);
}

void btc::execute(char *name_file)
{

	table_parser(name_file);
	// TEST
	for (std::map<std::string, double>::iterator it = _Data_Base.begin();
     it != _Data_Base.end(); ++it)
	{
 	   std::cout << it->first << " => " << it->second << std::endl;
	}

	return ;
}

const char	*btc::ErrorTableException::what() const throw()
{
	return ("Error in table");
}

const char	*btc::ErrorOpenigFileException::what() const throw()
{
	return ("Error opening file");
}
