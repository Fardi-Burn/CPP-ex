#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>

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

// Database parsing

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
	float		price;
	
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

// Input parser functions

void	btc::correct_format_input(std::string line)
{
	if (line.size() < 12)
		throw std::string("missing info");
	for (int i = 0; i < 4; i++)
	{
		if (!std::isdigit(line[i]))
			throw std::string("year format");
	}
	if (line[4] != '-')
		throw std::string("date format");
	for (int i = 5; i < 7; i++)
	{	
		if (!std::isdigit(line[i]))
			throw std::string("month format");
	}
	if (line[7] != '-')
		throw std::string("date format");
	for (int i = 8; i < 10; i++)
	{	
		if (!std::isdigit(line[i]))
			throw std::string("day format");
	}
	if (line[10] != ' ')
		throw std::string("missing ' ' char");
	if (line[11] != '|')
		throw std::string("missing '|' char");
	int year = (line[0] - '0') * 1000
             + (line[1] - '0') * 100
             + (line[2] - '0') * 10
             + (line[3] - '0');

    int month = (line[5] - '0') * 10
              + (line[6] - '0');

    int day = (line[8] - '0') * 10
            + (line[9] - '0');
	std::ostringstream oss;
	oss << "bad input => " << year << "-" << month << "-" << day;
	if (!isValidDate(year, month, day))
		throw (oss.str());
	return ;
}

void	btc::bitcoin_exchange(std::string line, std::string date)
{
	float	value;
	line.erase(std::remove(line.begin(), line.end(), ' '), line.end());
	std::istringstream iss(line);
	iss >> value;
	if (value > 1000)
		throw std::string("number too big");
	if (value < 0)
		throw std::string("number too small");
	std::cout << date << " " << value << std::endl;
}

void	btc::input_parser(std::string name_file)
{
	std::ifstream	file(name_file.c_str());
	std::string		line;
	

	if (!std::getline(file, line))
		throw (ErrorOpenigFileException());
	if (line != "date | value")
		throw (ErrorTableException());
	while(std::getline(file, line))
	{
		try 
		{
			this->correct_format_input(line);
			bitcoin_exchange(line.substr(12), line.substr(0, 10));
		}
		catch (std::string ex)
		{
			std::cout << "Error: " <<  ex << std::endl;
		}

	}
}

// Main function

void btc::execute(char *name_file)
{

	table_parser(name_file);
	input_parser(name_file);
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
