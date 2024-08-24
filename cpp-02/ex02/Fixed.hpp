#include <cmath>
#include <iostream>

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {

    private:
        int value;
        static const int bit = 8;

    public:
        Fixed(int value);
        Fixed(float value);
        Fixed();
        Fixed(Fixed const &other);
        Fixed& operator =( Fixed const &fix);
		Fixed& operator++();
		Fixed operator++(int);
        ~Fixed();
        float toFloat(void) const;
		Fixed operator + (const Fixed &_2);
		Fixed operator - (const Fixed &_2);
		Fixed operator * (const Fixed &_2);
		Fixed operator / (const Fixed &_2);
        int toInt(void) const;
		static Fixed& min(Fixed &_1, Fixed &_2);
		static Fixed min(const Fixed &_1,const Fixed &_2);
		static Fixed& max(Fixed &_1, Fixed &_2);
		static Fixed max(const Fixed &_1,const Fixed &_2);
};

std::ostream& operator << (std::ostream &out, const Fixed &fix);
bool operator == (const Fixed &_1, const Fixed &_2);
bool operator >= (const Fixed &_1, const Fixed &_2);
bool operator <= (const Fixed &_1, const Fixed &_2);
bool operator != (const Fixed &_1, const Fixed &_2);
bool operator > (const Fixed &_1, const Fixed &_2);
bool operator < (const Fixed &_1, const Fixed &_2);


#endif