#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
	public :
		Animal();
		Animal(const std::string &type);
		Animal(const Animal &Animal);
		virtual ~Animal();

		virtual void makeSound() const;

		std::string getType(void) const;

		Animal& operator=(const Animal &value);

	protected :
		std::string _type;
};

#endif
