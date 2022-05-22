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
        // default constructor
        ArrayList()         
        {
            cout << "default constructor is called" << endl;
            capacity = 1;
            used = 0;
            pArray = new int[capacity];
        }

        // copy constructor
        ArrayList(const ArrayList &arrayToCopy) 
        {
            cout << "copy constructor is called" << endl;
            capacity = arrayToCopy.getCapacity();
            used = arrayToCopy.size();
            pArray = new int[capacity];

            for (int i = 0; i < capacity; i++)
            {
                pArray[i] = arrayToCopy.getPArray()[i];
            }
        }

        // move constructor
        ArrayList(ArrayList&& arrayToMove) 
        {   
            cout << "move constructor is called" << endl;
            capacity = arrayToMove.capacity;
            used = arrayToMove.used;
            pArray = arrayToMove.pArray;
            arrayToMove.capacity = 0;
            arrayToMove.used = 0;
            arrayToMove.pArray = nullptr;
        }

        // copy assignment operator
        ArrayList& operator=(const ArrayList &rhs)
        {   
            cout << "copy assignment operator is called" << endl;
            // if the addresses are not the same, proceed with copying
            if (&rhs != this)
            {
                capacity = rhs.getCapacity();
                used = rhs.size();
                delete[] pArray; 
                pArray = new int[capacity];

                for (int i = 0; i < capacity; i++)
                {
                    pArray[i] = rhs.getPArray()[i];
                }
            }
            return *this;
        }

        // move assignment operator
        ArrayList& operator=(ArrayList &&rhs)
        {
            cout << "move assignment operator is called" << endl;
            if (&rhs != this)
            {
                delete[] pArray;
                capacity = rhs.capacity;
                used = rhs.used;
                pArray = rhs.pArray;
                rhs.pArray = nullptr;
            }
            return *this;
        }  

        // destructor
        ~ArrayList() 
        {
            delete[] pArray;
        }

        // determines whether used equals zero
        bool empty() const 
        {
            return used == 0;
        }

        // determines whether used equals capacity
        bool full() const 
        {
            return used == capacity;
        }

        // getters for all member variables
        int getCapacity() const 
        {
            return capacity;
        }

        int *getPArray() const 
        {
            return pArray;
        }

        int size() const 
        {
            return used;
        }

        // double the capacity of pArray 
        void resize 
        {
            int newCapacity = this->capacity * 2;
            int* newPArray =  new int[newCapacity];

            for (int i = 0; i < this->capacity; i++)
            {
                newPArray[i] = this->pArray[i];
            }
            this->capacity = newCapacity;
            delete[] this->pArray;
            this->pArray = newParray;
        }

        

        // << operator overload
        friend ostream &operator<<(ostream &output, const ArrayList &listToPrint)
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
};
