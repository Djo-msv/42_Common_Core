#ifndef FLOOR_HPP
# define FLOOR_HPP

# include "AMateria.hpp"

class Floor
{
	public :
		Floor();
		Floor(const Floor &value);
		~Floor();

		void addMateria(AMateria *materia, int i);

	private :
		AMateria	*_tab[1024];
};

#endif
