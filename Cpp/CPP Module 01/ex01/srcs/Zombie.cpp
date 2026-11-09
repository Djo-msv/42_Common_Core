#include "Zombie.hpp"

Zombie::Zombie(void)
{
	this->name = "default";
}

Zombie::~Zombie(void)
{}

void	Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setname(std::string name)
{
	this->name = name;
}

