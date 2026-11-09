#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "a Brain has just been created !" << std::endl;
	for (int i = 0; i != 100; i++)
		_ideas[i] = "";
}

Brain::Brain(const Brain &content)
{
	std::cout << "an Brain was copied !" << std::endl;	
	if (this == &content)
		return ;
	*this = content;
}

Brain::~Brain()
{
	std::cout << "a Brain has just been destroyed !" << std::endl;
}

void	Brain::setIdeas(std::string array[100]) const
{
	for (int i = 0; i != 100; i++)
		array[i] = _ideas[i];
}

Brain& Brain::operator=(const Brain &value)
{
	if (this == &value)
		return (*this);
	for (int i = 0; i != 100; i++)
		_ideas[i] = value._ideas[i];
	return (*this);
}
