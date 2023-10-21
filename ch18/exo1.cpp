#include "std_lib_facilities.h"

// copies a C-style string into memory allocated on free store.
// Do not use subscripting; use dereference operator instead.
char* strdup(const char* p) {
    char* cpy = new char;
    int i = 0;
    while(*(p+i) != 0) {
        *(cpy+i) = *(p+i);
        ++i;
    }
    return cpy;
}

// finds first occurence of C-style string x in s. 
// Do not use subscripting; use dereference operator instead.
char* findx(const char* s, const char* x) {
    // Match first letter
    int i = 0;
    while (*(s+i) != *x) {
        ++i;
    }
    // Check rest is a match
    int j = 1;
    if (*(s+i+j) != *(x+j)) {

    }

}

int main()
{
    char input[] = {'H', 'e', 'l', 'l', 'o', 0};
    char* res = strdup(input);
    cout << "Copy address: " << &res << endl;
    cout << "Value: "<< res << endl;
    return 0;
}
