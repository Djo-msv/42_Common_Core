#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>

# include "ICharacter.hpp"
# include "AMateria.hpp"
# include "Floor.hpp"

class Floor;

class Character : virtual public ICharacter
{
	public :
		Character();
		Character(const std::string &name);
		Character(const Character &value);
		~Character();

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);

		Character& operator=(const Character& value);

	protected :
		AMateria		*_tab[4];
		unsigned int	_NbMateria;
		std::string		_name;
		Floor			*_floor;
};

#endif
