#include "replace.hpp"

std::string replace_in_line(std::string line, std::string find, std::string replace)
{
    size_t f;
    size_t i;

    std::string str;
    f = line.find(find);
    i = 0;
    while (f != std::string::npos)
    {
        str.append(line.substr(i, f - i));
        str.append(replace);
        i = f + find.length();
        f = line.find(find, i); 
    }
    str.append(line.substr(i));
    str.append("\n");
    return (str);
}
