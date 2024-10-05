#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

void a()
{
	const AAnimal* Animals[100];
	for (int i = 0; i < 100; i++)
	{
		if (i % 2)
			Animals[i] = new Dog();
		else
			Animals[i] = new Cat();
	}

	for (int i = 0; i < 100; i++)
		delete Animals[i];
}

int main()
{
	const AAnimal *j = new Dog();
	const AAnimal *i = new Cat();
	i->makeSound(); 
	j->makeSound();
	delete j;
	delete i;

	return 0;
}