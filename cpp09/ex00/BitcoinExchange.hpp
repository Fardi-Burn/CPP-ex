#pragma once
# include <map>
# include <string>
# include <fstream>
# include <iostream>
# include <sstream>
# include <cstdlib>
# include <cctype>
# include <cstddef>
# include <stdexcept>
# include <algorithm>


class btc
{
	private:
		std::map<std::string, float> _Data_Base;
		std::map<std::string, double> _Date_Prices;
	public:
		btc();
		~btc();
		btc(const btc &other);
		btc &operator=(const btc &other);

		void	execute(char *name_file);
		void	table_parser(std::string name_file);
		int		map_maker(std::ifstream &data_base);
		int		correct_format_table(std::string line);
		int		isValidDate(int year, int month, int day);
		void	input_parser(std::string name_file);
		void	correct_format_input(std::string line);
		void	bitcoin_exchange(std::string line, std::string date);






		class ErrorOpenigFileException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class ErrorTableException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};
