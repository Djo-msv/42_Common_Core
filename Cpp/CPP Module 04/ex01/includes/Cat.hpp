#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	public :
		Cat();
		Cat(const Cat &Animal);
		~Cat();

		void makeSound() const;

		Cat& operator=(const Cat &value);

	private :
		Brain *_Brain;
};

#endif
