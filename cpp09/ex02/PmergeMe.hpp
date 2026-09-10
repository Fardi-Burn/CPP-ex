#pragma once
# include <cstddef>
# include <exception>
# include <string>
# include <cctype>
# include <climits>
# include <cstdlib>
# include <vector>
# include <iostream>
# include <algorithm>
# include <deque>

class PmergeMe {
	private:
		char				**_raw_argv;
		std::vector<int>	_numbers;
		std::vector<int>	_vec;
		std::deque<int>		_deq;
	public:

		// Constructors
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe operator=(const PmergeMe &other);
		~PmergeMe();
		PmergeMe(char **argv);

		// Members functions
		void	correct_argv();
		void	printVector(const std::vector<int>& numbers);
		void	before_after_print();
		void	special_cases();
		bool	is_sorted(std::vector<int> v) const;
		





		// exceptions
		class ArgumentsErrorException : public std::exception
		{
			private:
				std::string _message;
			public:
				ArgumentsErrorException(const std::string &argument);
				virtual ~ArgumentsErrorException() throw();
				virtual const char *what() const throw();
		};
		
		class GeneralErrorException : public std::exception
		{
			private:
				std::string _message;
			public:
				GeneralErrorException(const std::string &argument);
				virtual ~GeneralErrorException() throw();
				virtual const char *what() const throw();
		};

};
