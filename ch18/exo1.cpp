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
    char* p = nullptr;
    while (*s && *x) {
        if (*s == *x) {
            const char* save = x;
            p = const_cast<char*>(s);
            while (*s && *x) {
                if (*s != *x) {
                    x = save;
                    p = nullptr;
                    break;
                }
                ++s;
                ++x;
            }
        }
        else {
            ++s;
        }
    }
    return p;
}

// Write a function that compares C-style strings.
// Let it return a negative number if s1 is lexicographically before s2
// zero if s1 equals s2, and a positive number if s1 after s2.
// Do not use subscripting; use dereference operator instead.
int strcmp(const char* s1, const char* s2) {
    while (*s1 && *s2) {
        if (*s1 < *s2) {
            return -1;
        } else if (*s1 > *s2) {
            return 1;
        }           
        ++s1;
        ++s2;     
    }
    return 0;
}

int main()
{
    char input[] = {'H', 'e', 'l', 'l', 'o', 0};
    char* res = strdup(input);
    cout << "Copy address: " << &res << endl;
    cout << "Value: "<< res << endl;
    char match[] = {'l', 'o', 0};
    char* res2 = findx(input, match);
    cout << "Result: " << res2 << endl;
    string a = "Helloa";
    string b = "Hellob";
    cout << strcmp(a.c_str(), b.c_str())<<endl;
    cout << strcmp(b.c_str(), a.c_str())<<endl;
    cout << strcmp(a.c_str(), a.c_str())<<endl;
    return 0;
}
