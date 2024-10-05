#ifndef DOG_HPP
# define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog: public AAnimal {
	private:
		Brain *_Brain;
	public:
		Dog();
		~Dog();
		Dog(const Dog &other);
		Dog & operator =(const Dog &other);

		void makeSound() const;
} ;

#endif