#include "AMateria.hpp"

AMateria::AMateria() : _type("default")
{}

AMateria::AMateria(const std::string &type) : _type(type)
{}

AMateria::AMateria(const AMateria &value)
{
	if (this == &value)
		return ;
	*this = value;
}

AMateria::~AMateria()
{
}

AMateria& AMateria::operator=(const AMateria& value)
{
	(void)value;
	return (*this);
}

std::string const &AMateria::getType(void) const
{
	return (_type);
}

AMateria* AMateria::clone(void) const
{
	return (NULL);
}

void AMateria::use(ICharacter& target)
{
	(void)target;
}
