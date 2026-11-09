#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include <cstring>
# include <sstream>

# include "color.hpp"
# include "Contact.hpp"

class PhoneBook {

private:
	Contact contact[8];

public:
	int		get_all_contact();
	void	get_one_contact(int index);

	void	add_contact(std::string first_name, std::string last_name, std::string nickname, std::string number, std::string darkest_secret);

	PhoneBook();
};

#endif
