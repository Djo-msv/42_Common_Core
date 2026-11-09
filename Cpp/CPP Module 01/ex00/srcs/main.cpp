#include "Zombie.hpp"

int	main(void)
{
	Zombie *ZombieA = newZombie("Bob");

	randomChump("Henry");
	ZombieA->announce();

	delete ZombieA;
	return (0);
}
