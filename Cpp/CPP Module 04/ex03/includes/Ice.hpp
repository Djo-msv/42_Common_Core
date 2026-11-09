#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Ice : virtual public AMateria
{
	public :
		Ice();
		Ice(const Ice &value);
		virtual ~Ice();

		AMateria* clone() const;
		void use(ICharacter &target);

		Ice& operator=(const Ice& value);
};

#endif
