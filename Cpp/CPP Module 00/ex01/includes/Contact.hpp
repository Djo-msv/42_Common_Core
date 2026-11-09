#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact {

	private :
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	number;
		std::string	darkest_secret;

	public :
		std::string	get_first_name() const;
		std::string	get_last_name() const;
		std::string	get_nickname() const;
		std::string	get_number() const;
		std::string	get_darkest_secret() const;

		Contact();
		Contact(std::string first_name, std::string last_name, std::string nickname, std::string number, std::string darkest_secret);
};

#endif
