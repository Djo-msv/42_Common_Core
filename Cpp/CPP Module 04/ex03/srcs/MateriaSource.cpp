#include "MateriaSource.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

MateriaSource::MateriaSource() 
{
	_floor = new Floor();
	for (int i = 0; i != 4; i++)
		_materia[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &value)
{
	_floor = new Floor();
	if (this == &value)
		return ;
	*this = value;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i != 4; i++)
		delete _materia[i];
	delete _floor;
}

void MateriaSource::learnMateria(AMateria *value)
{
	int	i;

	if (!value)
	{
		std::cout << "Cannot learn NULL !" << std::endl;
		return ;
	}
	for (i = 0; i != 4 && _materia[i] != NULL; i++)
		continue ;
	if (i != 4)
		_materia[i] = value;
	else
	{
		delete value;
		std::cout << "Cannot learn anymore !" << std::endl;
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	int		i = 0;

	while (i != 4 && (_materia[i] == NULL || _materia[i]->getType() != type))
		i++;
	if (i != 4)
	{
		static int j = 0;
		AMateria *m = _materia[i]->clone();
		_floor->addMateria(m, j++);
		return (m);
	}
	return (NULL);
}

MateriaSource& MateriaSource::operator=(const MateriaSource& value)
{
	for (unsigned int i = 0; i != 4; i++)
		_materia[i] = value._materia[i];
	return (*this);
}
