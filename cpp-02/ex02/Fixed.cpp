#include "Fixed.hpp"

Fixed::Fixed()
{
    this->value = 0;
    std::cout << "Default constructor called!" << std::endl;
}

Fixed::Fixed(Fixed const &other)
{
    this->value = other.value;
    std::cout << "Copy constructor called!" << std::endl;
}

Fixed& Fixed::operator=(Fixed const &fix) {
    std::cout << "Copy Assignment operator called" << std::endl;
    if (this != &fix) {
        this->value = fix.value;
    }
    return *this; 
}
Fixed::Fixed(int value)
{
    this->value = value << this->bit;
    std::cout << "Int constructor called!" << std::endl;
}
Fixed::Fixed(float value)
{
    this->value = std::roundf(value * (1 << this->bit));
    std::cout << "Float constructor called!" << std::endl;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat(void) const {
        return (float)this->value / (1 << this->bit);
    }

int Fixed::toInt(void) const
{
	return this->value >> this->bit;
}

Fixed& Fixed::operator++()
{
	this->value++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
    ++value;
    return temp;
}

Fixed& Fixed::operator--()
{
	this->value--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
    --value;
    return temp;
}

std::ostream& operator << (std::ostream &out, const Fixed &fix)
{
    out << fix.toFloat();
    return (out);
}

bool operator == (const Fixed &_1, const Fixed &_2)
{
	if (_1.toFloat() == _2.toFloat())
		return (true);
	return (false);
}

bool operator >= (const Fixed &_1, const Fixed &_2)
{
	if (_1.toFloat() >= _2.toFloat())
		return (true);
	return (false);
}

bool operator <= (const Fixed &_1, const Fixed &_2)
{
	if (_1.toFloat() <= _2.toFloat())
		return (true);
	return (false);
}

bool operator != (const Fixed &_1, const Fixed &_2)
{
	if (_1.toFloat() != _2.toFloat())
		return (true);
	return (false);
}

bool operator > (const Fixed &_1, const Fixed &_2)
{
	if (_1.toFloat() > _2.toFloat())
		return (true);
	return (false);
}
bool operator < (const Fixed &_1, const Fixed &_2)
{
	if (_1.toFloat() < _2.toFloat())
		return (true);
	return (false);
}

Fixed Fixed:: operator + (const Fixed &_2)
{
	return (Fixed(this->toFloat() + _2.toFloat()));
}

Fixed Fixed:: operator - (const Fixed &_2)
{
	return (Fixed(this->toFloat() - _2.toFloat()));
}

Fixed Fixed:: operator * (const Fixed &_2)
{
	return (Fixed(this->toFloat() * _2.toFloat()));
}

Fixed Fixed:: operator / (const Fixed &_2)
{
	return (Fixed(this->toFloat() / _2.toFloat()));
}

Fixed& Fixed::min( Fixed &_1, Fixed &_2){
	if (_1 > _2)
		return (_2);
	else if (_2 > _1)
		return (_1);
	return (_1);
}
Fixed Fixed::min(const Fixed &_1,const Fixed &_2){
	if (_1 > _2)
		return (_2);
	else if (_2 > _1)
		return (_1);
	return (_1);
}

Fixed& Fixed::max( Fixed &_1, Fixed &_2){
	if (_1 > _2)
		return (_1);
	else if (_2 > _1)
		return (_2);
	return (_1);
}

Fixed Fixed::max(const Fixed &_1 ,const Fixed &_2){
	if (_1 > _2)
		return (_1);
	else if (_2 > _1)
		return (_2);
	return (_1);
}

