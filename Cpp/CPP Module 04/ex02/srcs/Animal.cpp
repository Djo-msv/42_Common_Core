#include "Animal.hpp"

Animal::Animal(void) : _type("default")
{
	std::cout << "an unknow Animal was create !" << std::endl;
}

Animal::Animal(const std::string &type) : _type(type)
{
	std::cout << "an Animal was create !" << std::endl;
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
	std::cout << "an Animal was destroy !" << std::endl;
}

void	Animal::makeSound() const
{
	std::cout << "an Animal sound." << std::endl;
}

Animal& Animal::operator=(const Animal &value)
{
	if (this == &value)
		return (*this);
	_type = value._type;
	return (*this);
}
