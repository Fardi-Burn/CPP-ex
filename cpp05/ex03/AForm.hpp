#ifndef AFORM_HPP
# define AFORM_HPP
# include <string>

class Bureaucrat;

class AForm
{
	private:
		const	std::string _name;
		bool				_signed;
		int 			_req_sign;
		int				_req_execute;
	public:
		// Constructors and destructors
		AForm();
		AForm(const AForm &other);
		AForm	&operator=(const AForm &other);
		virtual	~AForm();
		AForm(std::string name, int req_sign, int req_execute);
		// Getters
		std::string				getName() const;
		bool					getSigned() const;
		int						getReq_sign() const;
		int						getReq_execute() const;
		void					beSigned(Bureaucrat &bureau);
		virtual void			execute(Bureaucrat const &executor) const = 0;
		void					checkExecution(Bureaucrat const &executor) const;

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

		class NotSignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream& operator<<(std::ostream &os, const AForm &orm);

#endif
