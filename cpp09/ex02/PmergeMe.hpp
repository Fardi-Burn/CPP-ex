#pragma once
# include <cstddef>
# include <exception>
# include <string>
# include <cctype>
# include <climits>
# include <cstdlib>

class PmergeMe {
	private:
		char **_raw_argv;
	public:
		// Constructors
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe operator=(const PmergeMe &other);
		~PmergeMe();
		PmergeMe(char **argv);
		// Members functions
		void	correct_argv();
		

		class ArgumentsErrorException : public std::exception
		{
			private:
				std::string _message;
			public:
				ArgumentsErrorException(const std::string &argument);
				virtual ~ArgumentsErrorException() throw();
				virtual const char *what() const throw();
		};

};
