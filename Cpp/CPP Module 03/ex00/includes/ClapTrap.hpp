#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
	public :
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &value);
		~ClapTrap();

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		ClapTrap& operator=(const ClapTrap& value);

	private :
		std::string		_name;
		unsigned int	_hit_points;
		unsigned int	_energy_point;
		unsigned int	_attack_damage;
};

#endif
