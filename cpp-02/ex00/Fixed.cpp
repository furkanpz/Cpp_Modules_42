#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called!" << std::endl;
}

Fixed::Fixed(Fixed &other)
{
    this->value = other.value;
    std::cout << "Copy constructor called!" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &fix) {
    std::cout << "Assignment operator called" << std::endl;
    if (this != &fix) {
        this->value = fix.value;
    }
    return *this; 
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}