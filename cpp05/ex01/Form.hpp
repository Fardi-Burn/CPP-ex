#ifndef FORM_HPP
# define FORM_HPP
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const	std::string _name;
		bool				_signed;
		int 			_req_sign;
		int				_req_execute;
	public:
		// Constructors and destructors
		Form();
		Form(const Form &other);
		Form	&operator=(const Form &other);
		~Form();
		Form(std::string name, int req_sign, int req_execute);
		// Getters
		std::string			getName() const;
		bool				getSigned() const;
		int					getReq_sign() const;
		int					getReq_execute() const;
		void				beSigned(Bureaucrat &bureau);

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

		class AlreadySignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream& operator<<(std::ostream &os, const Form &orm);

#endif
