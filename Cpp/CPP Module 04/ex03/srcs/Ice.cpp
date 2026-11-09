#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{}

Ice::Ice(const Ice &value) : AMateria(value)
{}

Ice::~Ice()
{}

AMateria *Ice::clone() const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

Ice& Ice::operator=(const Ice& value)
{
	(void)value;
	return (*this);
}
