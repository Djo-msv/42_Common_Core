#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_hit_points = 100;
	_energy_point = 100;
	_attack_damage = 30;
	std::cout << "FragTrap constructor : " << _name << std::endl;
}

FragTrap::FragTrap(const FragTrap &value) : ClapTrap(value._name)
{
	if (this == &value)
		return ;
	*this = value;
	std::cout << "FragTrap constructor : " << _name << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << _name << " was destroy" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "High Fives !" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &value)
{
	if (this == &value)
		return (* this);
	_name = value._name;
	_hit_points = value._hit_points;
	_energy_point = value._energy_point;
	_attack_damage = value._attack_damage;
	return (*this);
}
