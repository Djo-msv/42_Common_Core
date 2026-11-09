#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Cure : virtual public AMateria
{
	public :
		Cure();
		Cure(const Cure &value);
		virtual ~Cure();

		AMateria* clone() const;
		void use(ICharacter &target);

		Cure& operator=(const Cure& value);
};

#endif
