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
        Fixed(Fixed &other);
        Fixed& operator =(const Fixed &fix);
        ~Fixed();
        float toFloat(void) const;
        int toInt(void) const;
};


#endif