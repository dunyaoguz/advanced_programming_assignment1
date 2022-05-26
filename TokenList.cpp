#include <iostream>
#include "TokenList.h"

// default constructor
TokenList::TokenList()
{
    std::cout << "Tokenlist default constructor is called." << std::endl;
    this->size = 0;
    this->head = new TNode{};  
    this->tail = new TNode{}; 
    this->head->next = this->tail;
}

// copy constructor
TokenList::TokenList(const TokenList& list)
{
    std::cout << "Tokenlist copy constructor is called." << std::endl;
    this->size = list.size();
    this->head = new TNode{};
    this->tail = new TNode{};

    TList::TNode *nodeBeingCopied = list.getHead();
    TList::TNode *newNode = this->head;

    // copy the head node
    addAfter(newNode, nodeBeingCopied->theToken);

    // copy the rest of the nodes
    while (nodeBeingCopied != list.getTail())
    {   
        nodeBeingCopied = nodeBeingCopied->next;
        addAfter(newNode, nodeBeingCopied->theToken);
        newNode = newNode->next;
    }
} 

// move constructor
TokenList::TokenList(TokenList&& list)
{
    std::cout << "Tokenlist move constructor is called." << std::endl;
    this->size = list.size();
    this->head = std::move(list.getHead());
    this->tail = std::move(list.getTail());
    list.size = 0;
}        

// copy assignment operator
TokenList& TokenList::operator=(const TokenList& rhs)
{
    std::cout << "Tokenlist copy assignment operator is called." << std::endl;
}

// move assignment operator
TokenList& TokenList::operator=(TokenList&& rhs)
{
    std::cout << "Tokenlist move assignment operator is called." << std::endl;
}          

// destructor
~TokenList::TokenList() 
{
    std::cout << "Tokenlist destructor is called." << std::endl;
} 

// determines whether the list is empty
bool TokenList::empty() const
{
    return this->theSize == 0;
}

// returns theSize
size_t TokenList::size() const
{
    return this->theSize;
}

// returns head TNode
TokenList::TNode *TokenList::getHead() const 
{
    return this->head;
}

// returns tail TNode
TokenList::TNode *TokenList::getTail() const 
{
    return this->tail;  
}

// returns the Token at the front of this TokenList
const Token& TokenList::front() const
{
    return this->head->theToken; 
}

// returns the Token at the back of this TokenList
const Token& TokenList::back() const;
{
    return this->tail->theToken;
}

// Adds a new node storing aToken after the node to
// which p points. If p is nullptr, it adds the node to
// the front of the list.
void TokenList::addAfter(TNode* p, const Token& aToken)
{
    TList::TNode *newNode = new TNode{aToken};
    if (p != nullptr) 
    {
        p.next = newNode;
    } 
    else 
    {
        this->head = newNode;
    }
}

void addSorted(const Token& aToken);
void addSorted(const string& str, int LineNum);
bool removeFront();
bool removeBack();
bool search(const Token& aToken) const;
void addFront(const Token& aToken);
void addBack(const Token& aToken);
bool remove(TNode* nodePtr);
TNode* lookup(const Token& aToken) const;
void print(ostream &output) const;
