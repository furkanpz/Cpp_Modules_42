#include <iostream>
#include <string>


int main()
{
    std::string a;
    getline(std::cin, a);
    try {
        printf("%i",std::stoi(a));

    }
    catch (std::invalid_argument )
    {
        printf("Hata\n");
    }
}