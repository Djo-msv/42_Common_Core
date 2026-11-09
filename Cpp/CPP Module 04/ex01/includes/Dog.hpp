#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	public :
		Dog();
		Dog(const Dog &Animal);
		~Dog();

		void makeSound() const;

		Dog& operator=(const Dog &value);

	private :
		Brain *_Brain;
};

#endif
