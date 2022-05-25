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
        size_t size{ 0 };               // counts the number of noded in the list
    
    public:
    
    
};