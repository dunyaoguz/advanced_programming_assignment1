#include <iostream>
#include "ArrayList.h"

// default constructor
ArrayList::ArrayList()         
{
    // std::cout << "Arraylist default constructor is called." << std::endl;
    this->capacity = 1;
    this->used = 0;
    this->pArray = new int[capacity];
}

// copy constructor
ArrayList::ArrayList(const ArrayList &arrayToCopy) 
{
    // std::cout << "Arraylist copy constructor is called." << std::endl;
    this->capacity = arrayToCopy.getCapacity();
    this->used = arrayToCopy.size();
    this->pArray = new int[capacity];

    for (int i = 0; i < capacity; i++)
    {
        this->pArray[i] = arrayToCopy.getPArray()[i];
    }
}

// move constructor
ArrayList::ArrayList(ArrayList&& arrayToMove) 
{   
    // std::cout << "Arraylist move constructor is called." << std::endl;
    this->capacity = arrayToMove.getCapacity();
    this->used = arrayToMove.size();
    this->pArray = arrayToMove.getPArray();
    arrayToMove.capacity = 0;
    arrayToMove.used = 0;
    arrayToMove.pArray = nullptr;
}

// copy assignment operator
ArrayList& ArrayList::operator=(const ArrayList &rhs)
{   
    // std::cout << "Arraylist copy assignment operator is called." << std::endl;
    // if the addresses are not the same, proceed with copying
    if (&rhs != this)
    {
        this->capacity = rhs.getCapacity();
        this->used = rhs.size();
        delete[] this->pArray; 
        this->pArray = new int[capacity];

        for (int i = 0; i < capacity; i++)
        {
            this->pArray[i] = rhs.getPArray()[i];
        }
    }
    return *this;
}

// move assignment operator
ArrayList& ArrayList::operator=(ArrayList &&rhs)
{
    // std::cout << "Arraylist move assignment operator is called." << std::endl;
    if (&rhs != this)
    {
        delete[] this->pArray;
        this->capacity = rhs.getCapacity();
        this->used = rhs.size();
        this->pArray = rhs.getPArray();
        rhs.capacity = 0;
        rhs.used = 0;
        rhs.pArray = nullptr;
    }
    return *this;
}  

// destructor
ArrayList::~ArrayList() 
{
    // std::cout << "Arraylist destructor is called." << std::endl;
    delete[] this->pArray;
}

// determines whether used equals zero
bool ArrayList::empty() const 
{
    return this->used == 0;
}

// determines whether used equals capacity
bool ArrayList::full() const 
{
    return this->used == this->capacity;
}

// getters for all member variables
int ArrayList::getCapacity() const 
{
    return this->capacity;
}

int *ArrayList::getPArray() const 
{
    return this->pArray;
}

int ArrayList::size() const 
{
    return this->used;
}

// inserts x at position used and then increments used by 1
void ArrayList::pushBack(int x) 
{
    // if we are at capacity
    if (this->capacity == this->used)
    {
        resize();
    }

    this->pArray[this->used] = x; 
    this->used++;
}

// determines whether x occurs in the list
bool ArrayList::contains(int x) const 
{
    for (int i = 0; i < this->used; i++)
    {
        if (x == this->pArray[i])
        {
            return true;
        }
    } 
    return false;
}

// places the value stored at position in the reference parameter value and returns true
// if position is out of range, returns false 
bool ArrayList::get(int position, int& value) const
{
    if(position > this->capacity) 
    {
        return false;
    }
    value = this->pArray[position];
    return true;
}

// double the capacity of pArray 
void ArrayList::resize() 
{
    int newCapacity = this->capacity * 2;
    int* newPArray =  new int[newCapacity];

    for (int i = 0; i < this->capacity; i++)
    {
        newPArray[i] = this->pArray[i];
    }
    this->capacity = newCapacity;
    delete[] this->pArray;
    this->pArray = newPArray;
}

// << operator overload
std::ostream &operator<<(std::ostream &output, const ArrayList &listToPrint)
{
    // if used is 0, return empty string because we can't print anything
    if (listToPrint.size() == 0)
    {
        return output;
    }
    for (int i = 0; i < listToPrint.size(); i++)
    {
        output << listToPrint.pArray[i] << " ";
    }
    return output;
}

void ArrayList::print(std::ostream &output) const
{
    for (int i = 0; i < this->used; i++)
    {
        output << pArray[i] << " ";
    }
}