#ifndef FORM_HPP
# define FORM_HPP
# include <string>
# include "Bureaucrat.hpp"

class Form
{
	private:
		const	std::string _name;
		bool				_signed;
		const	int 		_req_sign;
		const	int			_req_execute;
	public:
		// Constructors and destructors
		Form();
		Form(const Form &other);
		Form	&operator=(const Form &other);
		~Form();
		Form(std::string name, int req_sign, int req_execute);
		// Getters
		const std::string	getName();
		const bool			getSigned();
		const int			getReq_sign();
		const int			getReq_execute();
		void				beSigned(Bureaucrat bureau);
		
		// exceptions
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

#endif
