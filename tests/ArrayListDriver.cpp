#include <iostream>
#include <cassert>
#include "ArrayList.h"

using std::cout;
using std::endl;


int main()
{
    std::cout << "Tesing ArrayList!\n";
    ArrayList list{};
    cout << "list-1 -> " << list << endl;
    assert(list.getCapacity() == 1);

    list.pushBack(19);
    cout << "list-2 -> " << list << endl;
    assert(list.getCapacity() == 1);
    assert(list.size() == 1);

    list.pushBack(32);
    cout << "list-3 -> " << list << endl;
    assert(list.getCapacity() == 2);
    assert(list.size() == 2);

    list.pushBack(21);
    cout << "list-4 -> " << list << endl;
    assert(list.getCapacity() == 4);
    assert(list.size() == 3);

    list.pushBack(7);
    cout << "list-5 -> " << list << endl;
    assert(list.getCapacity() == 4);
    assert(list.size() == 4);

    list.pushBack(18);
    cout << "list-6 -> " << list << endl;
    assert(list.getCapacity() == 8);
    assert(list.size() == 5);

    cout << "ArrayList Test Successful" << endl;
    return 0;
}