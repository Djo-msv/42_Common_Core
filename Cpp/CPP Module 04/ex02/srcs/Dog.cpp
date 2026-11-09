#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	_Brain = new Brain();
	std::cout << "a dog has just been created !" << std::endl;
}

Dog::Dog(const Dog &value) : Animal(value)
{
	if (this == &value)
		return ;
	std::cout << "a dog has just been copied !" << std::endl;
	_Brain = new Brain(*value._Brain);
	*this = value;
}

Dog::~Dog()
{
	delete _Brain;
	std::cout << "a dog has just been destroy !" << std::endl;
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
	*_Brain = *value._Brain;
	return (*this);
}
