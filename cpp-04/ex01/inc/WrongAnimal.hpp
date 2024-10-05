#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>
#include <string>


class WrongAnimal 
{
	protected:
		std::string type;
	public:
		WrongAnimal();
		virtual ~WrongAnimal();
		WrongAnimal(const WrongAnimal &other);
		WrongAnimal & operator = (const WrongAnimal &other);

		std::string getType() const;
		virtual void makeSound() const;
};


#endif