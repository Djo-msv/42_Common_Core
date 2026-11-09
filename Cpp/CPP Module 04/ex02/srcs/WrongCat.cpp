#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "a WrongCat has just been created !" << std::endl;
}

WrongCat::WrongCat(const WrongCat &value) : WrongAnimal(value._type)
{
	std::cout << "a WrongCat has just been copied !" << std::endl;

	if (this == &value)
		return ;
	*this = value;
}

WrongCat::~WrongCat()
{
	std::cout << "a WrongCat has just been destroy." << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "Wrong Meow" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &value)
{
	if (this == &value)
		return (*this);
	_type = value._type;
	return (*this);
}
 
