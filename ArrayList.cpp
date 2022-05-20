#include<iostream>
#include<string>
#include "ArrayList.h"

using namespace std;

// default constructor          
ArrayList::ArrayList() 
{
    capacity = 1;
    used = 0;
    pArray = new int[capacity];
}

// copy constructor
ArrayList::ArrayList(const ArrayList &arrayToCopy) 
{
    capacity = arrayToCopy.getCapacity();
    used = arrayToCopy.getUsed();
    pArray = new int[capacity];
}

// move constructor
ArrayList::ArrayList(ArrayList&& arrayToMove) 
{
    capacity = arrayToMove.capacity;
    used = arrayToMove.used;
    arrayToMove.capacity = 0;
    arrayToMove.used = 0;
}

// getters
int ArrayList::getCapacity() const 
{
    return capacity;
}

int ArrayList::getUsed() const 
{
    return used;
}

int *ArrayList::getPArray() const 
{
    return pArray;
}

