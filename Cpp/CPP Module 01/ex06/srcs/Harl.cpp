#include "Harl.hpp"

Harl::Harl(void){}

Harl::~Harl(void){}

void Harl::debug(void)
{
	std::cout << "[ DEBUG ]\n" << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl << std::endl;
}

void Harl::info(void)
{
	std::cout << "[ INFO ]\n" << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl << std::endl;
}

void Harl::warning(void)
{
	std::cout << "[ WARNING ]\n" <<"I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl << std::endl;
}

void Harl::error(void)
{
	std::cout << "[ ERROR ]\n"<< "This is unacceptable! I want to speak to the manager now." << std::endl << std::endl;
}

void Harl::complain(std::string level)
{
	int	i = 0;

	std::string	str[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void(Harl::*funcs[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	while (i != 4 && str[i].compare(level))
		i++;
	switch (i)
	{
		case 0:
			(this->*funcs[0])();
		case 1:
			(this->*funcs[1])();
		case 2:
			(this->*funcs[2])();
		case 3:
		{
			(this->*funcs[3])();
			break ;
		}
		default :
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;

	}
}
