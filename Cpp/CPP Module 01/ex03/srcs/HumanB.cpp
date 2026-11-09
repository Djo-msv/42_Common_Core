#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->_name = name;
	this->_type = NULL;
}

HumanB::~HumanB(){}

void	HumanB::attack(void)
{
	if (_type)
		std::cout << _name << " attacks with their " << (*_type).getType() << std::endl;
	else
		std::cout << _name << " cannot attack" << std::endl;
}

void	HumanB::setWeapon(Weapon &type)
{
	_type = &type;
}
