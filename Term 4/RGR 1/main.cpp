#include <iostream>
#include <fstream>
#include "lexer.hpp"


int main()
{
    std::ifstream fin("code.karl");

    if (!fin.is_open())
        return 1;

    char c;
    while(fin.get(c))
    {
        std::cout << "[ " << transliterator(c).clazz << " " << (char)transliterator(c).value << " ] ";
    }
    std:: cout << std::endl;

    return 0;
}