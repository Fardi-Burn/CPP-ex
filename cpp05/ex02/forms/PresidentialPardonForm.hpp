#pragma once

# include "../AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string _target;
	public:
		PresidentialPardonForm(std::string target);
		~PresidentialPardonForm();

		void	execute(const Bureaucrat &executor) const;
};
