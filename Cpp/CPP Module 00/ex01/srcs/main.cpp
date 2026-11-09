#include "PhoneBook.hpp"

void	erase_line(int i)
{
	for (int j = 0; j != i; j++)
		std::cout << "\033[1A" << "\33[2K\r";
}

void	take_contact(PhoneBook& phonebook)
{
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	number;
	std::string	darkest_secret;

	std::cout << "contact first name\n : ";
	getline(std::cin, first_name);
	erase_line(2);
	if (first_name == "")
	{
		std::cout << P_RED << "Wrong text\n"
			<< P_NOC " : Press enter to continue\n";
		getline(std::cin, first_name);
		erase_line(3);
		return ;
	}
	std::cout << "contact last name\n : ";
	getline(std::cin, last_name);
	erase_line(2);
	if (last_name == "")
	{
		std::cout << P_RED << "Wrong text\n"
			<< P_NOC " : Press enter to continue\n";
		getline(std::cin, first_name);
		erase_line(3);
		return ;
	}
	std::cout << "contact nickname\n : ";
	getline(std::cin, nickname);
	erase_line(2);
	if (nickname == "")
	{
		std::cout << P_RED << "Wrong text\n"
			<< P_NOC " : Press enter to continue\n";
		getline(std::cin, first_name);
		erase_line(3);
		return ;
	}
	std::cout << "contact number\n : ";
	getline(std::cin, number);
	erase_line(2);
	if (number == "")
	{
		std::cout << P_RED << "Wrong text\n"
			<< P_NOC " : Press enter to continue\n";
		getline(std::cin, first_name);
		erase_line(3);
		return ;
	}
	std::cout << "contact darkest_secret\n : ";
	getline(std::cin, darkest_secret);
	erase_line(2);
	if (darkest_secret == "")
	{
		std::cout << P_RED << "Wrong text\n"
			<< P_NOC " : Press enter to continue\n";
		getline(std::cin, first_name);
		erase_line(3);
		return ;
	}
	phonebook.add_contact(first_name, last_name, nickname, number, darkest_secret);	
}

bool	isNumber(std::string str)
{
	if (str.empty())
		return false;
    for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
        if (!std::isdigit(*it)) return false;
    }
    return true;
}

void	search_contact(PhoneBook& phonebook)
{
	std::string			str;
	std::stringstream	index;
	int					i;
	int					j;

	j = phonebook.get_all_contact();
	std::cout << "\nselect contact : ";
	getline(std::cin, str);
	erase_line(j + 3);
	if (!isNumber(str))
	{
		std::cout << P_RED << "take numeric argument !\n"
			<< P_NOC " : Press enter to continue\n";
		getline(std::cin, str);
		erase_line(3);
		return ;
	}
	index << str;
	index >> i;
	if (i >= 8)
	{
		std::cout << P_RED << "inexistant contact\n"
			<< P_NOC " : Press enter to continue\n";
		getline(std::cin, str);
		erase_line(3);
		return;
	}
	phonebook.get_one_contact(i);
}

void exec(void)
{
	std::string	str;
	PhoneBook phonebook;

	while (1)
	{
		std::cout << "Please, enter a command ("
			<< P_GREEN << "ADD"
			<< P_NOC << ", "
			<< P_YELLOW << "SEARCH"
			<< P_NOC << " or "
			<< P_RED << "EXIT"
			<< P_NOC << ")\n : ";
		if (!getline(std::cin, str))
			return ;
		erase_line(2);
		if (str == "EXIT")
			return ;
		else if (str == "ADD")
			take_contact(phonebook);
		else if (str == "SEARCH")
			search_contact(phonebook);
	}
}

int	main(void)
{
	exec();
	return (0);
}

