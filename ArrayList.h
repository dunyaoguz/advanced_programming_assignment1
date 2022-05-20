#include<iostream>
#include<string>
using namespace std;

class ArrayList 
{     
    private:
        int capacity;       // capacity of the array
        int used;           // number of array elements currently in use       
        int* pArray;        // pointer to a dynamically allocated array of integers
    
    public:  
        // constructors
        ArrayList();                                // default constructor
        ArrayList(const ArrayList &arrayToCopy);    // copy constructor
        ArrayList(ArrayList&& arrayToMove);         // move constructor 

        // getters
        int getCapacity() const;
        int getUsed() const;
        int *getPArray() const;

        // operator overload
        friend ostream &operator<<(ostream &sout, const ArrayList &someList);
};
