#include "BitcoinExchange.hpp"
#include <cstddef>
#include <stdexcept>
#include <string>

void	btc::table_parser(std::string name_file)
{
	std::ifstream		data_base("data.csv");
	std::stringstream	data_line;
	std::ifstream		file(name_file);
	std::stringstream	line;

	if (!data_base.is_open())
		throw (ErrorOpenigFileException());
	data_line << data_base.rdbuf();
	if (!file.is_open())
		throw (ErrorOpenigFileException());
	if (!this->map_maker(data_line.str()))
		throw (std::runtime_error("Error in data base format"));
	file.close();
	data_base.close();
}

int	btc::correct_format(std::string line)
{
	if (!line.find(','))
		return (0);
	std::string	date = line.substr(0, line.find(','));
	std::size_t firstDash = date.find('-');
	std::size_t secondDash = date.find('-', firstDash + 1);

	std::string yearStr = date.substr(0, firstDash);
	std::string monthStr = date.substr(firstDash + 1,
                                    secondDash - firstDash - 1);
	std::string dayStr = date.substr(secondDash + 1);
	// CONTINUAR CODIGO AQUI
	return (1);

}

int	btc::map_maker(std::string data_base)
{
	std::string	line;
	std::string	date;
	std::string	priceStr;
	size_t		comma;
	double		price;
	
	if (std::getline(data_base, line) != "date,exchange_rate")
		return (0);

	while(std::getline(data_base, line))
	{
		if (!this->correct_format(line))
			return (1);
		comma = line.find(',');
		date = line.substr(0, comma);
		price = std::stod(line.substr(comma + 1));
		_Data_Base[date] = price;
	}

	return (1);
}

void btc::execute(char *name_file)
{

	table_parser(name_file);
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
