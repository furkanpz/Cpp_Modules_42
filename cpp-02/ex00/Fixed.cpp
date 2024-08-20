#include "Fixed.hpp"

Fixed::Fixed()
{
    this->value = 0;
    std::cout << "Default constructor called!" << std::endl;
}

Fixed::Fixed(Fixed &other)
{
    this->value = other.value;
    std::cout << "Copy constructor called!" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &fix) {
    std::cout << "Copy Assignment operator called" << std::endl;
    if (this != &fix) {
        this->value = fix.getRawBits();
    }
    return *this; 
}

int Fixed::getRawBits (void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->value);
}

void Fixed::setRawBits (int const raw) 
{
    this->value = raw;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}