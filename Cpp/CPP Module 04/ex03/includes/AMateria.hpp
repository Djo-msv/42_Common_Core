#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>

# include "ICharacter.hpp"
# include "Character.hpp"

class ICharacter;

class AMateria
{
	public:
		AMateria();
		AMateria(const std::string &type);
		AMateria(const AMateria &value);
		virtual ~AMateria();

		std::string const & getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);

		AMateria& operator=(const AMateria& value);

	protected:
		const std::string _type;
};

#endif
