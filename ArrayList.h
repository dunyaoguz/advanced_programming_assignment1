#include <iostream>
#ifndef ARRAYLIST_H
#define ARRAYLIST_H

using namespace std;

class ArrayList 
{     
    private:
        int capacity;       // capacity of the array
        int used;           // number of array elements currently in use       
        int* pArray;        // pointer to a dynamically allocated array of integers
        void resize(); 
    
    public:       
        // constructors
        ArrayList();                                    // default constructor
        ArrayList(const ArrayList &arrayToCopy);        // copy constructor
        ArrayList(ArrayList&& arrayToMove);             // move constructor

        // assignment operators
        ArrayList& operator=(const ArrayList &rhs);     // copy assignment operator
        ArrayList& operator=(ArrayList &&rhs);          // move assignment operator

        ~ArrayList();                                   // destructor

        // getters
        int getCapacity() const;
        int *getPArray() const;
        int size() const;

        // member functions
        bool empty() const;
        bool full() const;
        bool contains(int x) const;
        bool get(int position, int& value) const;
        void pushBack(int x);

        // << operator overload
        friend ostream &operator<<(ostream &output, const ArrayList &listToPrint);
};
#endif

