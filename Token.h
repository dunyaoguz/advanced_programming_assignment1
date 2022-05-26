#include <iostream>
#include <cstring>
#include <cctype>
#include "ArrayList.h"
#ifndef TOKEN_H
#define TOKEN_H

class Token 
{ 
    private: 
        char* cstr;                 // pointer to an array of characters storing the characters in this token
        int frequency;              // number of occurences of this token
        ArrayList number_list;      // list of line numbers associated with this token

    public:
        // constructors
        Token();                                       // default constructor
        Token(const char* chars, int line_num);        // normal constructor
        Token(const Token& token);                     // copy constructor
        Token(Token&& token);                          // move constructor

        // assignment operators
        Token& operator=(const Token& rhs);            // copy assignment operator
        Token& operator=(Token&& rhs);                 // move assignment operator

        ~Token();                                      // destructor

        // getters
        char *c_str() const; 
        const ArrayList& getNumberList() const;
        int getFrequency() const;

        // member functions
        void addLineNumber(int line_num);
        int size() const;
        int compare(const Token& aToken) const;
        void print(std::ostream &output) const;

        // >> operator overload
        friend std::ostream &operator<<(std::ostream &output, const Token &tokenToPrint);
};
#endif