#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "a cat has just been created !" << std::endl;
}

Cat::Cat(const Cat &value) : Animal(value._type)
{
	std::cout << "a cat has just been copied !" << std::endl;

	if (this == &value)
		return ;
	*this = value;
}

Cat::~Cat()
{
	std::cout << "a cat has just been destroyed." << std::endl;
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
	return (*this);
}
