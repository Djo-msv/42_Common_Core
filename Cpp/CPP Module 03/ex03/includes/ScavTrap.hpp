#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public :
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &value);
		virtual ~ScavTrap();

		virtual void attack(const std::string& target);

		void guardGate();

		ScavTrap& operator=(const ScavTrap& value);

	protected :
		static unsigned int	scav_energy;
};

#endif
