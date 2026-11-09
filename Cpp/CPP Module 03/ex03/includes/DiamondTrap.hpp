#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	public :
		DiamondTrap();
		DiamondTrap(std::string _name);
		DiamondTrap(const DiamondTrap &value);
		virtual ~DiamondTrap();

		void whoAmI(void);

		DiamondTrap& operator=(const DiamondTrap& value);	

	private :
		std::string	_name;
};

#endif
