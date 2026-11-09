
#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{}

Cure::Cure(const Cure &value) : AMateria(value)
{}

Cure::~Cure()
{}

AMateria *Cure::clone(void) const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}

Cure& Cure::operator=(const Cure& value)
{
	(void)value;
	return (*this);
}
