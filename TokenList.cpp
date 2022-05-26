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
    if (&rhs != this) 
    {
        // delete old stuff
        TList::TNode *oldNode = this->head;
        TList::TNode *tempNode;
        while (oldNode != this->tail)
        {
            tempNode = oldNode;
            oldNode = oldNode->next;
            delete[] tempNode;
        }
        delete this->tail;
        
        // copy new stuff
        this->size = rhs.size();
        this->head = new TNode{};
        this->tail = new TNode{};

        TList::TNode *nodeBeingCopied = rhs.getHead();
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
    return *this;
}

// move assignment operator
TokenList& TokenList::operator=(TokenList&& rhs)
{
    std::cout << "Tokenlist move assignment operator is called." << std::endl;
    if (&rhs != this)
    {
        // delete old stuff
        TList::TNode *oldNode = this->head;
        TList::TNode *tempNode;
        while (oldNode != this->tail)
        {
            tempNode = oldNode;
            oldNode = oldNode->next;
            delete[] tempNode;
        }
        delete this->tail;

        // move new stuff
        this->size = list.size();
        this->head = std::move(list.getHead());
        this->tail = std::move(list.getTail());
        list.size = 0;
    }
    return *this;
}          

// destructor
~TokenList::TokenList() 
{
    std::cout << "Tokenlist destructor is called." << std::endl;
    TList::TNode *oldNode = this->head;
    TList::TNode *tempNode;
    while (oldNode != this->tail)
    {
        tempNode = oldNode;
        oldNode = oldNode->next;
        delete[] tempNode;
    }
    delete this->tail;
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
    this->size = this->size + 1;
}

// If the list is nonempty, removes the node at the front of the list and returns true; 
// otherwise, returns false
bool removeFront() 
{
    if(this->head != nullptr) 
    {
        TList::TNode *oldNode = this->head;
        this->head = oldNode.next;
        delete[] oldNode;

        this->size = this->size - 1;
        return true;
    }
    else 
    {
        return false;
    }
}

// If the list is nonempty, removes the node at the end of the list and returns true; 
// otherwise, returns false
bool removeBack()
{
    if(this->tail != nullptr) 
    {
        // get the node before tail
        TList::TNode *oldNode = this->head;
        while (oldNode->next != this->tail)
        {
            oldNode = oldNode->next;
        }
        delete[] this->tail;
        this->tail = oldNode;
        this->tail.next = nullptr;

        this->size = this->size - 1;
        return true;
    }
    else 
    {
        return false;
    }
}

// Removes the node to which nodePtr points and returns true; 
// otherwise, returns false.
bool remove(TNode* nodePtr)
{
    if((nodePtr != this->head) && (nodePtr != this->tail))
    {
        // get the Node after nodePtr
        TList::TNode *nextNode = nodePtr.next;
        // get the node before nodePtr
        TList::TNode *oldNode = this->head;
        while (oldNode->next != nodePtr)
        {
            oldNode = oldNode->next;
        }
        oldNode.next = nextNode;
        delete[] nodePtr;
        this->size = this->size - 1;
    }
    else 
    {
        return false;
    }
}

// Adds a new node storing aToken to the front of the list
void addFront(const Token& aToken)
{
    TList::TNode *newNode = new TNode{aToken};
    if(this-> head != nullptr)
    {
        newNode.next = this->head;
        this->head = newNode;
    }
    else 
    {
        this->head = newNode;
    }
    this->size = this->size + 1;
}

// Adds a new node storing aToken to the end of the list
void addBack(const Token& aToken)
{
    TList::TNode *newNode = new TNode{aToken};
    if(this-> head != nullptr)
    {
        this->tail.next = newNode;
        this->tail = newNode;
    }
    else 
    {
        this->head = newNode;
    }
    this->size = this->size + 1;
}

// determines whether aToken is in the list
bool search(const Token& aToken) const
{
   TList::TNode *currentNode = this->head;
    while (currentNode != nullptr)
    {
        Token* currentToken = currentNode.theToken;
        if(aToken.compare(currentToken) == 0) 
        {
            return true;
        }
        currentNode = currentNode.next;
    }
    return false;
}

// Adds aToken at its sorted position into the list so
// as to maintain the ascending order of the tokens in the list
void addSorted(const Token& aToken)
{

}

// Equivalent to addSorted(Token(str,lineNum));
// but it's up to you to decide how you want to implement it.
void addSorted(const string& str, int LineNum)
{

}

TNode* lookup(const Token& aToken) const;
void print(ostream &output) const;
