#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>

# include "IMateriaSource.hpp"

class MateriaSource : virtual public IMateriaSource
{
	public :
		MateriaSource();
		MateriaSource(const MateriaSource &value);
		~MateriaSource();

		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);

		MateriaSource& operator=(const MateriaSource& value);
	
	private :
		AMateria *_materia[4];
		Floor		*_floor;
};

#endif
