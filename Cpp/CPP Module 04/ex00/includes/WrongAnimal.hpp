#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
	public :
		WrongAnimal();
		WrongAnimal(const std::string &type);
		WrongAnimal(const WrongAnimal &Animal);
		virtual ~WrongAnimal();

		void makeSound() const;

		std::string getType(void) const;

		WrongAnimal& operator=(const WrongAnimal &value);

	protected :
		std::string _type;
};

#endif
