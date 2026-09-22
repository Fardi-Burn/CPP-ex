#pragma once
# include <cstddef>
# include <exception>
# include <string>
# include <cctype>
# include <climits>
# include <cstdlib>
# include <utility>
# include <vector>
# include <iostream>
# include <algorithm>
# include <deque>
# include <map>

class PmergeMe {
	private:
		char				**_raw_argv;
	public:
		std::vector<int>	_numbers;
		std::vector<int>	_vec;
		std::deque<int>		_deq;

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
		bool	comparePairs(const std::pair<int, int> &a, const std::pair<int, int> &b);
		bool	is_sorted(std::vector<int> v) const;
		void	sortVector(std::vector<int> &nums);
		void	sortDeque(std::deque<int>& nums);
		void	insertPending(std::vector<int>& mainChain, const std::vector<std::pair<int, int> >& pair);
		std::vector<size_t>	jacobsthalOrder(size_t size);
		bool	is_duplicated(std::vector<int> v) const;
		void	insertPending_d(std::deque<int>& mainChain, const std::deque<std::pair<int, int> >& pairs);
		std::deque<size_t>	jacobsthalOrder_d(size_t size);




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
