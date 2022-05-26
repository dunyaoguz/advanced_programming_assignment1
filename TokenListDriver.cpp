#include <iostream>
#include "TokenList.h"

using std::cout;
using std::endl;

int main()
{
    TokenList bucket;
    Token t1("Hello", 1); 
    bucket.addSorted(t1);
    // bucket.addFront(t1);
    // bucket.addBack(t1);
    Token t2("Hello", 11); 
    bucket.addSorted(t2);
    // bucket.addFront(t2);
    // bucket.addBack(t2);
    Token t3("Hello", 111); 
    bucket.addSorted(t3);
    // bucket.addFront(t3);
    // bucket.addBack(t3);
    Token tArray[]{ Token("How", 1), Token("are", 11), Token("you", 2),
    Token("today?", 22), Token("#tag", 3), Token("bye", 3) };
    
    for (Token t : tArray)
    { 
        bucket.addSorted(t);
        // bucket.addBack(t);
        // bucket.addFront(t);
    }
    bucket.print(cout); // ideally we prefer cout << bucket << endl;
    cout << endl;
    cout << "Success!" << endl;
    return 0; // 0 means success!
}