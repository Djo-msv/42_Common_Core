#include <iostream>
#include <string>

void	capitalize(std::string str)
{
	for (std::string::iterator it = str.begin(); it != str.end(); it++)
		*it = std::toupper(*it);
	std::cout << str << std::endl;
}

int	main(int argc, char **argv)
{
	std::string	str;

	if (argc <= 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (1);
	}
	for (int i = 1; i != argc; ++i)
	{
		str = argv[i];
		capitalize(str);
	}
	return (0);
}
