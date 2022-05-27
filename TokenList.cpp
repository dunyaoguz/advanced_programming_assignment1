#include <iostream>
#include "Token.h"
#include "TokenList.h"
#include "ArrayList.h"

// default constructor
TokenList::TokenList() : head{}, tail{}, theSize{}
{
    std::cout << "Tokenlist default constructor is called." << std::endl;
}

// copy constructor
TokenList::TokenList(const TokenList& list)
{
    std::cout << "Tokenlist copy constructor is called." << std::endl;
    this->theSize = list.size();
    this->head = new TNode(list.front());
    this->tail = new TNode(list.back());

    TokenList::TNode *nodeBeingCopied = list.getHead();
    TokenList::TNode *newNode = this->head;

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
    this->theSize = list.size();
    this->head = std::move(list.getHead());
    this->tail = std::move(list.getTail());
    list.theSize = 0;
}        

// copy assignment operator
TokenList& TokenList::operator=(const TokenList& rhs)
{
    std::cout << "Tokenlist copy assignment operator is called." << std::endl;
    if (&rhs != this) 
    {
        // delete old stuff
        TokenList::TNode *oldNode = this->head;
        TokenList::TNode *tempNode;
        while (oldNode != this->tail)
        {
            tempNode = oldNode;
            oldNode = oldNode->next;
            free(tempNode);        
        }
        free(this->tail);
        
        // copy new stuff
        this->theSize = rhs.size();
        this->head = new TNode(rhs.front());
        this->tail = new TNode(rhs.back());

        TokenList::TNode *nodeBeingCopied = rhs.getHead();
        TokenList::TNode *newNode = this->head;

        // copy the head node
        addAfter(newNode, nodeBeingCopied->theToken);

        // copy the rest of the nodes
        while (nodeBeingCopied != rhs.getTail())
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
        TokenList::TNode *oldNode = this->head;
        TokenList::TNode *tempNode;
        while (oldNode != this->tail)
        {
            tempNode = oldNode;
            oldNode = oldNode->next;
            free(tempNode);        
        }
        free(this->tail);

        // move new stuff
        this->theSize = rhs.size();
        this->head = std::move(rhs.getHead());
        this->tail = std::move(rhs.getTail());
        rhs.theSize = 0;
    }
    return *this;
}          

// destructor
TokenList::~TokenList() 
{
    std::cout << "Tokenlist destructor is called." << std::endl;
    TokenList::TNode *oldNode = this->head;
    TokenList::TNode *tempNode;
    while (oldNode != this->tail)
    {
        tempNode = oldNode;
        oldNode = oldNode->next;
        free(tempNode);        
    }
    free(this->tail);
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
const Token& TokenList::back() const
{
    return this->tail->theToken;
}

// Adds a new node storing aToken after the node to
// which p points. If p is nullptr, it adds the node to
// the front of the list.
void TokenList::addAfter(TNode* p, const Token& aToken)
{
    TokenList::TNode *newNode = new TNode(aToken);
    if (p != nullptr) 
    {
        // new Node points to what p was previously pointing to
        newNode->next = p->next;
        p->next = newNode;
    } 
    else 
    {
        this->head = newNode;
        this->tail = newNode;
    }
    this->theSize++;
}

// If the list is nonempty, removes the node at the front of the list and returns true; 
// otherwise, returns false
bool TokenList::removeFront() 
{
    if(this->head != nullptr) 
    {
        TokenList::TNode *oldNode = this->head;
        this->head = oldNode->next;
        delete[] oldNode;

        this->theSize--;
        return true;
    }
    else 
    {
        return false;
    }
}

// If the list is nonempty, removes the node at the end of the list and returns true; 
// otherwise, returns false
bool TokenList::removeBack()
{
    if(this->tail != nullptr) 
    {
        // get the node before tail
        TokenList::TNode *oldNode = this->head;
        while (oldNode->next != this->tail)
        {
            oldNode = oldNode->next;
        }
        delete[] this->tail;
        this->tail = oldNode;
        this->tail->next = nullptr;

        this->theSize--;
        return true;
    }
    else 
    {
        return false;
    }
}

// Removes the node to which nodePtr points and returns true; 
// otherwise, returns false.
bool TokenList::remove(TNode* nodePtr)
{
    if((nodePtr != this->head) && (nodePtr != this->tail))
    {
        // get the Node after nodePtr
        TokenList::TNode *nextNode = nodePtr->next;
        // get the node before nodePtr
        TokenList::TNode *oldNode = this->head;
        while (oldNode->next != nodePtr)
        {
            oldNode = oldNode->next;
        }
        oldNode->next = nextNode;
        free(nodePtr);
        this->theSize--;
        return true;
    }
    else 
    {
        return false;
    }
}

// Adds a new node storing aToken to the front of the list
void TokenList::addFront(const Token& aToken)
{
    TokenList::TNode *newNode = new TNode(aToken);
    if(this->head != nullptr)
    {
        newNode->next = this->head;
        this->head = newNode;
    }
    else 
    {
        this->head = this->tail = newNode;
    }
    this->theSize++;
}

// Adds a new node storing aToken to the end of the list
void TokenList::addBack(const Token& aToken)
{
    TokenList::TNode *newNode = new TNode(aToken);
    if(this->tail == nullptr)
    {
        this->head = this->tail = newNode;
    }
    else 
    {
        this->tail->next = newNode;
        this->tail = newNode;
    }
    this->theSize++;
}

// determines whether aToken is in the list
bool TokenList::search(const Token& aToken) const
{
    TokenList::TNode *currentNode = this->head;
    while (currentNode != nullptr)
    {
        if(currentNode->theToken.compare(aToken) == 0) 
        {
            return true;
        }
        currentNode = currentNode->next;
    }
    return false;
}

// Adds aToken at its sorted position into the list so
// as to maintain the ascending order of the tokens in the list
void TokenList::addSorted(const Token& aToken)
{
    ArrayList list = aToken.getNumberList();
    int line_number;
    list.get(list.size() - 1, line_number); // never returns false here (why?)
    addSorted(aToken.c_str(), line_number);
}

// Equivalent to addSorted(Token(str,lineNum));
void TokenList::addSorted(const std::string& str, int lineNumber)
{
    Token aToken(str.c_str(), lineNumber);    // create a node with str and lineNumber
    TNode* nodePtr = lookup(aToken);          // look it up in the list
    
    // should aToken be the first node?
    // lookup provides this information by returning nullptr
    if (nodePtr == nullptr)
    {
        addFront(aToken);
        return; // done
    }
    
    // aToken cannot be the first token;
    // hence, whether or not aToken is already in the list,
    // nodePtr must point to one of the nodes in the list,
    // including the first, last, and the nodes in between.
    // could it be that nodePtr's token is equal to aToken?
    if ((nodePtr->theToken).compare(aToken) == 0)
    {
        // yes, we have a repeated token, so we only add its line number
        (nodePtr->theToken).addLineNumber(lineNumber);
        return; // done
    }
    else
    {
        // we have a new token,
        // so we add it to the list after the node nodePtr is pointing at.
        addAfter(nodePtr, aToken);
        return; // done
    }
}

// If aToken is in the list, it returns a pointer to the node whose token 
// is equal to aToken; otherwise, it returns a pointer to the node after 
// which aToken would be inserted in the sorted list.
TokenList::TNode* TokenList::lookup(const Token& aToken) const
{
    // nullptr means that aToken must be the first node
    if (head == nullptr) 
    {
        return nullptr; 
    }
    // aToken should be placed at head 
    if (aToken.compare(head->theToken) < 0)
    {
        return nullptr; 
    }

    // aToken is equal to head
    if (aToken.compare(head->theToken) == 0)
    {
        return this->head; 
    }

    TokenList::TNode* prev = head;          
    TokenList::TNode* current = head->next;
    
    while (current != nullptr)
    {   
        std::cout << "iter" << std::endl;
        if ((current->theToken).compare(aToken) > 0)
        {   
            return prev;
        }
        prev = current;        
        current = current->next;
    }
    return nullptr;
}

// prints the entire list to sout
void TokenList::print(std::ostream &output) const
{
    if(this->theSize  ==  0)
    {
        std::cout << "empty TokenList" << std::endl;
    }   
    else
    {
        TokenList::TNode *current = this->head;
        int counter = 0;
        do
        {
            current->theToken.print(output);
            current = current->next;
            counter++;
        } while (theSize != counter);
    }
}
