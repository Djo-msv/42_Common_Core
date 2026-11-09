
#include "Character.hpp"

Character::Character() : _NbMateria(0), _name("default")
{
	for (int i = 0; i != 4; i++)
		_tab[i] = NULL;
}

Character::Character(const std::string &name) :  _NbMateria(0), _name(name)
{
	for (int i = 0; i != 4; i++)
		_tab[i] = NULL;
}
 
Character::Character(const Character &value)
{
	if (this == &value)
		return ;
	*this = value;
}

Character::~Character()
{}

std::string const &Character::getName(void) const
{
	return (_name);
}

void Character::equip(AMateria *m)
{
	if (!m)
		return ;
	_tab[_NbMateria % 4] = m;
	_NbMateria++;
}

void Character::unequip(int idx)
{
	_tab[idx % 4] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	if (_tab[idx % 4])
		_tab[idx % 4]->use(target);
	else
		std::cout << "Can't use !" << std::endl;
}

Character& Character::operator=(const Character& value)
{
	_name = value._name;
	_NbMateria = value._NbMateria;
	for (unsigned int i = 0; i != 4; i++)
		_tab[i] = value._tab[i];
	return (*this);
}
