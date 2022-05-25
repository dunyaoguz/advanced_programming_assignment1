#include <iostream>
#include <cassert>

int main()
{
    char a = 'a';
    // this doesnt work
    // const char *b = 'b'; 
    const char *b = "b"; // works
    char *c;
    c = &a;

    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "a: " << &a << std::endl; // cant print address of a variable
    std::cout << "b: " << &b << std::endl;
    std::cout << "c: " << c << std::endl;
    std::cout << "c: " << *c << std::endl;

    return 0;
};
