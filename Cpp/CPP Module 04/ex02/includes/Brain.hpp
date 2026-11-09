#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
	public :
		Brain();
		Brain(const Brain &content);
		~Brain();

		void setIdeas(std::string array[100]) const;

		Brain& operator=(const Brain &value);

	private :
		std::string _ideas[100];
};

#endif
