#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap()
{}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name + "_clap_name"), FragTrap(name + "_clap_name")
{
	_name = name;
	_energy_point = ScavTrap::scav_energy;
	std::cout << "DiamondTrap constructor : " << _name << std::endl;
	std::cout << "hit point : " << _hit_points << std::endl
		<< "energy_point : " << _energy_point << std::endl
		<< "attack damage : " << _attack_damage << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &value) : ClapTrap(value)
{
	if (this == &value)
		return ;
	*this = value;
	std::cout << "DiamondTrap constructor : " << _name << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << _name << " was destroy" << std::endl;
}

void DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap name : " << _name << std::endl
		<< "ClapTrap name : " << ClapTrap::_name << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &value)
{
	if (this == &value)
		return (* this);
	_name = value._name;
	_hit_points = value._hit_points;
	_energy_point = value._energy_point;
	_attack_damage = value._attack_damage;
	return (*this);
}
