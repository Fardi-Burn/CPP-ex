#pragma once
#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

class btc
{
	private:
		std::map<std::string, double> _Data_Base;
		std::map<std::string, double> _Date_Prices;
	public:
		btc();
		~btc();
		btc(const btc &other);
		btc &operator=(const btc &other);

		void	execute(char *name_file);
		void	table_parser(std::string name_file);
		int		map_maker(std::string data_base);
		int		correct_format(std::string line);








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
