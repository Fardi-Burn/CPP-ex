#include "BitcoinExchange.hpp"


int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Incorrect amount of argument" << std::endl;
		return (1);
	}
	try 
	{
		btc	BitcoinExchange;

		BitcoinExchange.execute(argv[1]);
	} 	
	catch(std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
	}
	return (0);
}
