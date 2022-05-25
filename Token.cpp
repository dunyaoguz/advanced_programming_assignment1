#include <iostream>
#include <cstring>
#include <cctype>
#include "Token.h"

using namespace std;

// default constructor
Token::Token() 
{
    this->frequency = 0;
    this->cstr[0] = '\0';
}

// normal constructor
Token::Token(const char* chars, int line_num)
{
    this->cstr = new char[strlen(chars)];
    for (int i = 0; i < strlen(chars); i++)
    {
        this->cstr[i] = chars[i];
    }
    this->frequency = 1;
    this->number_list.pushBack(line_num);
}

// copy constructor
Token::Token(const Token& token)
{
    cout << "Token copy constructor is called." << endl;
    this->frequency = token.getFrequency();
    this->number_list = token.getNumberList();
    this->cstr = new char[token.size()];

    for (int i = 0; i < token.size(); i++)
    {
        this->cstr[i] = token.c_str()[i];
    }
}

// move constructor
Token::Token(Token&& token)
{
    cout << "Token move constructor is called." << endl;
    this->cstr = token.cstr;
    this->frequency = token.frequency;
    this->number_list = token.number_list;
    token.cstr = nullptr;
    token.frequency = 0;
    // token.number_list = nullptr; --> why is this not working?
}

// copy assignment operator
Token& Token::operator=(const Token& rhs)
{
    cout << "Token copy assignment operator is called." << endl;
    // if the addresses are not the same, proceed with copying
    if (&rhs != this)
    {
        this->frequency = rhs.getFrequency();
        this->number_list = rhs.getNumberList();
        delete[] this->cstr; 
        this->cstr = new char[rhs.size()];

        for (int i = 0; i < rhs.size(); i++)
        {
            this->cstr[i] = rhs.c_str()[i];
        }
    }
    return *this;
}

// move assignment operator
Token& Token::operator=(Token &&rhs)
{
    cout << "Token move assignment operator is called." << endl;
    if (&rhs != this)
    {
        delete[] this->cstr;
        this->frequency = rhs.frequency;
        this->number_list = rhs.number_list;
        this->cstr = rhs.cstr;
        rhs.cstr = nullptr;
        rhs.frequency = 0;
    }
    return *this;
}

// destructor
Token::~Token()
{
    cout << "Token destructor is called." << endl;
    delete[] this->cstr;
}

// returns a constant pointer to this token's cstr
char *Token::c_str() const 
{
    return this->cstr;
}

// returns this token's list of line numbers
const ArrayList& Token::getNumberList() const
{
    return this->number_list;
} 

// returns this token's frequency
int Token::getFrequency() const 
{
    return this->frequency;
}

// adds line num to the end of this token's number list
void Token::addLineNumber(int line_num)
{
    this->number_list.pushBack(line_num);
    this->frequency++;
}

// returns the length of this token's cstr
int Token::size() const 
{
    if (this->cstr != NULL) 
    {
        return strlen(this->cstr); 
    }
    else 
    {
        return 0;
    }  
}

// returns -1, 0, or 1, depending on whether this token's
// cstr is less than, equal to, or grater than aToken's cstr
int Token::compare(const Token& aToken) const
{
    if(strcmp(this->cstr, aToken.c_str()) < 0)
    {
        return 1;
    }
    else if(strcmp(this->cstr, aToken.c_str()) == 0) 
    {
        return 0;
    }
    else 
    {
        return 1;
    }
}

// << operator overload
// prints this token's cstr followed by its number list
ostream &operator<<(ostream &output, const Token &tokenToPrint)
{
    // if used is 0, return empty string because we can't print anything
    if (tokenToPrint.size() == 0)
    {
        return output;
    }
    for (int i = 0; i < tokenToPrint.size(); i++)
    {
        output << tokenToPrint.c_str()[i] << " ";
    }
    output << " " << tokenToPrint.number_list;
    return output;
}

void Token::print(ostream &output) const
{
    output << this->cstr << " " << "(" << this->frequency << ")";
    output << " " << this->number_list << endl;
}