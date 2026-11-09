#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap c("Claude");
	for (int i = 0; i < 5; i++)
		c.attack("the void");
	c.takeDamage(9);
	c.beRepaired(4294967286);
	c.beRepaired(-1);
	c.beRepaired(0);
	c.beRepaired(1);
	return (0);
}
