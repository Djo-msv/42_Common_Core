#include "Zombie.hpp"

int	main(void)
{
	int		N = 16;
	Zombie *Z = zombieHorde(N, "Rafael");

	for (int i = 0; i != N; i++)
		Z[i].announce();
	delete [] Z;
	return (1);
}
