#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_hit_points = 100;
	_energy_point = 50;
	_attack_damage = 20;
	std::cout << "ScavTrap constructor : " << _name << std::endl; 
}

ScavTrap::ScavTrap(const ScavTrap &value) : ClapTrap(value._name)
{
	if (this == &value)
		return ;
	*this = value;
	std::cout << "ScavTrap constructor : " << _name << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << _name << " was destroy" << std::endl;
}

void	ScavTrap::attack(const std::string &target)
{
	if (_hit_points == 0 || _energy_point == 0)
		return ;
	_energy_point--;
		std::cout << "ScavTrap : " << _name << std::endl
		<< "attack target : " << target << std::endl
		<< "amount : " << _attack_damage << std::endl
		<< "energy point : " << _energy_point << std::endl
		<< "hit points : " << _hit_points << std::endl << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode." << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &value)
{
	if (this == &value)
		return (* this);
	_name = value._name;
	_hit_points = value._hit_points;
	_energy_point = value._energy_point;
	_attack_damage = value._attack_damage;
	return (*this);
}
