#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	_Brain = new Brain();
	std::cout << "a cat has just been created !" << std::endl;
}

Cat::Cat(const Cat &value) : Animal(value)
{
	if (this == &value)
		return ;
	std::cout << "a cat has just been copied !" << std::endl;
	_Brain = new Brain(*value._Brain);
	*this = value;
}

Cat::~Cat()
{
	delete _Brain;
	std::cout << "a cat has just been destroy." << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}

Cat& Cat::operator=(const Cat &value)
{
	if (this == &value)
		return (*this);
	_type = value._type;
	*_Brain = *value._Brain;
	return (*this);
}
