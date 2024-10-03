#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

void a()
{
	const Animal* Animals[100];
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
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	Animal a;
	i->makeSound(); // will output the cat sound!
	j->makeSound();
	delete j;
	delete i;

	return 0;
}