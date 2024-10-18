#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	const WrongAnimal* j = new WrongCat();
	const Animal* i = new Cat();


	i->makeSound();
	j->makeSound();


}