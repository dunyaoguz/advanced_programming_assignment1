#include <iostream>
#include <cstring>
#include <cctype>
#include "ArrayList.h"

using namespace std;

class Token 
{ 
    private: 
        char* cstr;                 // pointer to an array of characters storing the characters in this token
        int frequency;              // number of occurences of this token
        ArrayList number_list;    // list of line numbers associated with this token

    public:
        // default constructor
        Token() 
        {
            this->frequency = 0;
            this->cstr[0] = '\0';
        }

        // normal constructor
        Token(const char* chars, int line_num)
        {
            this->cstr = new char[strlen(chars)];
            for (int i = 0; i < strlen(chars); i++)
            {
                this->cstr[i] = chars[i];
            }
            this->frequency = 1;
            this->number_list.pushback(line_num);
        }
}