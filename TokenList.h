#include <iostream>
#include "Token.h"

#ifndef TOKENLIST_H_
#define TOKENLIST_H_

class TokenList {
    private:
        // a private "member type"
        struct TNode
        {
            Token theToken;         // the token contained in this node
            TNode* next;            // Pointer to the next node or nullptr

            // constructors
            TNode(const Token& aToken, TNode* next = nullptr) : theToken(aToken), next(next) {}
            TNode() = delete;                           // default ctor
            TNode(const TNode& other) = delete;         // copy ctor
            TNode(TNode&& other) = delete;              // move ctor

            TNode& operator=(const TNode& other) = delete;      // copy assignment
            TNode& operator=(TNode&& other) = delete;           // move assignment
            virtual ~TNode() = default;
        }; 

    private:
        TNode* head{ nullptr };         // points to the first node in the list
        TNode* tail{ nullptr };         // points to the last node in the list
        size_t theSize{ 0 };            // counts the number of nodes in the list

        bool remove(TNode* nodePtr);
        TNode* lookup(const Token& aToken) const;
        void addAfter(TNode* p, const Token& aToken);
    
    public:
        // constructors
        TokenList();                        // default constructor
        TokenList(const TokenList& list);   // copy constructor
        TokenList(TokenList&& list);        // move constructor

        // assignment operators
        TokenList& operator=(const TokenList& rhs);     // copy assignment operator
        TokenList& operator=(TokenList&& rhs);          // move assignment operator

        ~TokenList();                                   // destructor

        // member functions
        bool empty() const;
        size_t size() const;
        TNode *getHead() const;
        TNode *getTail() const;

        void print(std::ostream &output) const;
        const Token& front() const;
        const Token& back() const;
        void addSorted(const Token& aToken);
        void addSorted(const string& str, int LineNum);
        bool removeFront();
        bool removeBack();
        bool search(const Token& aToken) const;
        void addFront(const Token& aToken);
        void addBack(const Token& aToken);
};
#endif