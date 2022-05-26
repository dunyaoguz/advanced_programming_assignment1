#include <iostream>
#include "TokenList.h"

// default constructor
TokenList()
{

}

// copy constructor
TokenList(const TokenList& list)
{

} 

// move constructor
TokenList(TokenList&& list)
{

}        

// copy assignment operator
TokenList& operator=(const TokenList& rhs)
{

}

// move assignment operator
TokenList& operator=(TokenList&& rhs)
{

}          

// destructor
~TokenList() 
{

} 

// member functions
bool empty() const;
size_t size() const;
void print(ostream &output) const;
const Token& front() const;
const Token& back() const;
void addSorted(const Token& aToken);
void addSorted(const string& str, int LineNum);
bool removeFront();
bool removeBack();
bool search(const Token& aToken) const;
void addFront(const Token& aToken);
void addBack(const Token& aToken);
bool remove(TNode* nodePtr);
TNode* lookup(const Token& aToken) const;
void addAfter(TNode* p, const Token& aToken);