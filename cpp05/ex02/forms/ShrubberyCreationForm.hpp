#pragma once

# include "../AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string _target;
	public:
		ShrubberyCreationForm(std::string target);
		~ShrubberyCreationForm();

		void	execute(const Bureaucrat &executor) const;
};
