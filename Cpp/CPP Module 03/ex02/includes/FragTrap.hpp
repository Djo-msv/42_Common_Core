#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public :
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap &value);
		virtual ~FragTrap();

		void highFivesGuys(void);

		FragTrap& operator=(const FragTrap& value);
};

#endif
