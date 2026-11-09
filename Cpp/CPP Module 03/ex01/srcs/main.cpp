#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap	Clap1("Claude");
	ClapTrap	Clap2(Clap1);

	ScavTrap	Scav1("Siri");
	ScavTrap	Scav2(Scav1);
	Scav2.guardGate();
	Scav1.attack("the void");
}
