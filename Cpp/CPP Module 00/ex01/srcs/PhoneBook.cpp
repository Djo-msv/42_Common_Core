#include "PhoneBook.hpp"

void	erase_line(int i);

PhoneBook::PhoneBook(void)
{}

void	print_tab(std::string str)
{
	int	len;

	len = std::strlen(str.c_str());
	if (len >= 10)
		std::cout << str.substr(0, 9) << ".";
	else
		std::cout << std::string(10 - len, ' ') << str;
}

int	PhoneBook::get_all_contact(void)
{
	int		i;
	Contact	contact;
	std::stringstream index;
	
	std::cout << P_TEAL << "   index  |first name| last name| nickname\n" << P_NOC;
	for (i = 0; i < 8; i++)
	{
		index << i;
		const Contact& contact = this->contact[i];
		if (contact.get_last_name() == "")
			break;
		print_tab(index.str());
		std::cout << P_GREEN << "|" << P_NOC;
		print_tab(contact.get_first_name());
		std::cout << P_GREEN << "|" << P_NOC;
		print_tab(contact.get_last_name());
		std::cout << P_GREEN << "|" << P_NOC;
		print_tab(contact.get_nickname());
		std::cout << std::endl;
		index.str("");
	}
	return (i);
}

void	PhoneBook::get_one_contact(int index)
{
	std::string	tmp;
	const Contact& contact = this->contact[index];

	if (contact.get_last_name() == "")
	{
		std::cout << P_RED << "inexistant contact\n"
			<< P_NOC " : Press enter to continue\n";
		getline(std::cin, tmp);
		erase_line(3);

		return ;
	}
	std::cout << "first name     : " << contact.get_first_name() << std::endl;
	std::cout << "last name      : " << contact.get_last_name() << std::endl;
	std::cout << "nickname       : " << contact.get_nickname() << std::endl;
	std::cout << "number         : " << contact.get_number() << std::endl;
	std::cout << "darkest secret : " << contact.get_darkest_secret() << std::endl << std::endl;
	std::cout << " : Press enter to continue\n";
	
	getline(std::cin, tmp);
	erase_line(8);

}

void	PhoneBook::add_contact(std::string first_name, std::string last_name, std::string nickname, std::string number, std::string darkest_secret)
{
	static int index = 0;

	this->contact[index % 8] = Contact(first_name, last_name, nickname, number, darkest_secret);
	index++;
}

