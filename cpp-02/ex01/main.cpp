#include "Fixed.hpp"

int main() {
    Fixed a(10); // Tam sayı ile başlatma
    Fixed b(42.42f); // Kayan nokta ile başlatma
    Fixed c(a); // Kopya yapıcı
    Fixed d; // Varsayılan yapıcı

    d = b; // Atama operatörü

    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;

    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;

    return 0;
}