#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
	public :
		virtual ~Animal();

		virtual void makeSound() const = 0;

		std::string getType() const;
		void	setType(const std::string type);

		Animal& operator=(const Animal &value);

	protected :
		Animal();
		Animal(const std::string &type);
		Animal(const Animal &Animal);
		std::string _type;
};

#endif
