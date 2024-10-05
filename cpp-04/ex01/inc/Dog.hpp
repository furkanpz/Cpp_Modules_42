#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal {
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