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
    return this->capacity;
}

int ArrayList::getUsed() const 
{
    return this->used;
}

int *ArrayList::getPArray() const 
{
    return this->pArray;
}

std::ostream &operator<<(std::ostream &output, const IntList &someList)
{
    //base case if used is 0, then we have a fresh/empty array; return empty string
    if (someList.getUsed() == 0)
    {
        return output;
    }
    for (int i = 0; i < someList.getUsed(); i++)
    {
        output << someList.dynarray[i] << " ";
    }
    return output;
}