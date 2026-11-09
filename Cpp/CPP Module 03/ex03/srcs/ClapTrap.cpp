#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("default"), _hit_points(0), _energy_point(0), _attack_damage(0)
{}

ClapTrap::ClapTrap(std::string name) : _name(name), _hit_points(10), _energy_point(10), _attack_damage(0)
{
	std::cout << "ClapTrap constructor : " << _name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &value)
{
	if (this == &value)
		return ;
	*this = value;
	std::cout << "ClapTrap constructor : " << _name << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " was destroy" << std::endl;
}

void	ClapTrap::attack(const std::string &target)
{
	if (_hit_points == 0 || _energy_point == 0)
		return ;
	_energy_point--;
	std::cout << "ClapTrap : " << _name << std::endl
		<< "attack target : " << target << std::endl
		<< "amount : " << _attack_damage << std::endl
		<< "energy point : " << _energy_point << std::endl
		<< "hit points : " << _hit_points << std::endl << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (amount > _hit_points)
		_hit_points = 0;
	else
		_hit_points -= amount;
	std::cout << "ClapTrap : " << _name << std::endl
		<< "takeDamage, amount : " << amount << std::endl
		<< "hit points : " << _hit_points << std::endl << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_hit_points == 0 || _energy_point == 0)
		return ;
	if (amount > 4294967295 - _hit_points)
		_hit_points = 4294967295;
	else
		_hit_points += amount;
	_energy_point -= 1;
	std::cout << "ClapTrap : " << _name << std::endl
		<< "be repaired, amount : " << amount << std::endl
		<< "energy point : " << _energy_point << std::endl
		<< "hit points : " << _hit_points << std::endl << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &value)
{
	if (this == &value)
		return (* this);
	_name = value._name;
	_hit_points = value._hit_points;
	_energy_point = value._energy_point;
	_attack_damage = value._attack_damage;
	return (*this);
}
