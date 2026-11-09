#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "----- Basic test -----" << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    const WrongAnimal* a = new WrongAnimal();
    const WrongAnimal* b = new WrongCat();
    const WrongCat* c = new WrongCat();

    std::cout << "Dog sound: ";
    j->makeSound();
    std::cout << "Cat sound: ";
    i->makeSound();
    std::cout << "WrongAnimal sound: ";
    a->makeSound();
    std::cout << "WrongCat sound: ";
    b->makeSound();
    std::cout << "WrongCat2 sound: ";
    c->makeSound();

    delete j;
    delete i;
    delete a;
    delete b;
    delete c;

    std::cout << "\n----- Array test -----" << std::endl;
    Animal* animals[8];
    for (int index = 0; index < 4; index++)
    {
        animals[index] = new Dog();
        std::cout << "Dog" << index << " sound: ";
        animals[index]->makeSound();
    }
    for (int index = 4; index < 8; index++)
    {
        animals[index] = new Cat();
        std::cout << "Cat" << (index - 4) << " sound: ";
        animals[index]->makeSound();
    }
	for (int index = 0; index < 8; index++)
		delete animals[index];

    std::cout << "\n----- Deep copy test -----" << std::endl;
    Dog dog1;
    Dog dog2(dog1);
	dog2 = dog1;
    std::cout << "Dog2 sound: ";
    dog2.makeSound();

    Cat cat1;
	Cat cat2(cat1);
	cat2 = cat1;
    std::cout << "Cat2 sound: ";
    cat2.makeSound();

    return 0;
}
