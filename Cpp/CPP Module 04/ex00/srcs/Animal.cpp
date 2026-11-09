#include "Animal.hpp"

Animal::Animal(void) : _type("default")
{
	std::cout << "an unknow Animal was created !" << std::endl;
}

Animal::Animal(const std::string &type) : _type(type)
{
	std::cout << "an Animal was created !" << std::endl;
}

Animal::Animal(const Animal &Animal)
{
	std::cout << "an Animal was copied !" << std::endl;	
	if (this == &Animal)
		return ;
	*this = Animal;
}

Animal::~Animal()
{
	std::cout << "an Animal was destroyed !" << std::endl;
}

void	Animal::makeSound() const
{
	std::cout << "an unknown animal sound." << std::endl;
}

std::string	Animal::getType(void) const
{
	return (_type);
}

Animal& Animal::operator=(const Animal &value)
{
	if (this == &value)
		return (*this);
	_type = value._type;
	return (*this);
}
