#include <iostream>
#include "Dictionary.h"

int main()
{
    const char *filename = "input.txt";

    Dictionary dunyasDictionary{filename};

    dunyasDictionary.print(std::cout);
    std::cout << std::endl;
    return 0;
}