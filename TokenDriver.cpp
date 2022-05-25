#include <iostream>
#include <cassert>
#include "Token.h"

using std::cout;
using std::endl;

int main()
{
    std::cout << "Testing an Object of Class Token\n";
    Token t1{ "Hello", 1 };

    // ideally we want to print t1 like this (easy to implement)
    // cout << "A) t1: " << t1 << '\n';
    cout << "A) t1: "; t1.print(cout); cout << '\n';
    t1.addLineNumber(11);
    t1.addLineNumber(13);
    t1.addLineNumber(74);
    t1.addLineNumber(92);
    cout << "B) t1: "; t1.print(cout); cout << '\n';

    Token t2 = t1; // copy constructor (not copy assignment)
    t1.addLineNumber(11111);
    cout << "C) t1: "; t1.print(cout); cout << '\n';
    cout << "D) t2: "; t2.print(cout); cout << '\n'; 
    t2 = t1; // copy assignment
    cout << "E) t1: "; t1.print(cout); cout << '\n';
    cout << "F) t2: "; t2.print(cout); cout << '\n';

    Token t3 = std::move(t2); // move constructor
    cout << "G) t3: "; t3.print(cout); cout << '\n';
    cout << "H) t2: "; t2.print(cout); cout << '\n'; // warning C26800:
    // Use of a moved from object
    
    t1 = std::move(t3); // move assignment
    cout << "I) t3: "; t3.print(cout); cout << '\n'; // warning C26800:
    // Use of a moved from object
    cout << "J) t1: "; t1.print(cout); cout << '\n';
    
    ArrayList ia = t1.getNumberList();
    cout << "J) ia: "; ia.print(cout); cout << '\n';
    
    return 0;
}