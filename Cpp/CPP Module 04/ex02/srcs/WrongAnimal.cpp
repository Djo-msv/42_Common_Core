#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("default")
{
	std::cout << "an unknow WrongAnimal was create !" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string &type) : _type(type)
{
	std::cout << "an WrongAnimal was create !" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &WrongAnimal)
{
	std::cout << "an WrongAnimal was copied !" << std::endl;	
	if (this == &WrongAnimal)
		return ;
	*this = WrongAnimal;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "an WrongAnimal was destroy !" << std::endl;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "an unknown animal sound." << std::endl;
}

std::string	WrongAnimal::getType(void) const
{
	return (_type);
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &value)
{
	if (this == &value)
		return (*this);
	_type = value._type;
	return (*this);
}

