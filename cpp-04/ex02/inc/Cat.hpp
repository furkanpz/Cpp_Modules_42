#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat: public AAnimal {
	private:
		Brain *_Brain;
	public:
		Cat();
		~Cat();
		Cat(const Cat &other);
		Cat &operator = (const Cat &other);

		void makeSound() const;
};


#endif