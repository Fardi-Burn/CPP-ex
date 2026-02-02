#ifndef PHONEBOOK_H
# define PHONEBOOK_H
# include "contact.hpp"

class PhoneBook 
{
	private:
		Contact contacts[8];
	public:
		// Constructor
		PhoneBook();
		void	add_contact(std::string first_name, std::string last_name, std::string nickname
				, std::string phone_number, std::string darkest_secret);
};

#endif
