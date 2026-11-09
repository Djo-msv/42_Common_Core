#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "a dog has just been created !" << std::endl;
}

Dog::Dog(const Dog &value) : Animal(value._type)
{
		std::cout << "a dog has just been copied !" << std::endl;

	if (this == &value)
		return ;
	*this = value;
}

Dog::~Dog()
{
	std::cout << "a dog has just been destroyed !" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "Wow" << std::endl;
}

Dog& Dog::operator=(const Dog &value)
{
	if (this == &value)
		return (*this);
	_type = value._type;
	return (*this);
}
