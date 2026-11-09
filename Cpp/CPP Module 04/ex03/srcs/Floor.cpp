#include "Floor.hpp"

Floor::Floor()
{
	for (int i = 0; i != 1024; i++)
		_tab[i] = NULL;
}

Floor::Floor(const Floor &value)
{
	(void)value;
	for (int i = 0; i != 1024; i++)
		_tab[i] = NULL;
}

Floor::~Floor()
{
	for (int i = 0; i != 1024; i++)
		delete _tab[i];
}

void	Floor::addMateria(AMateria *m, int i)
{
	if (i > 1024)
	{
		delete m;
		m = NULL;
		return ;
	}
	_tab[i] = m;
	(void)m;
	(void)i;
}
