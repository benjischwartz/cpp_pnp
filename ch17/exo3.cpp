#include "std_lib_facilities.h"


const char minVal = 'A';
const char maxVal = 'Z';
const char a = 'a';
const char z = 'z';
// replaces all uppercase characters in C-style string s with their lowercase equivalents.
// C-style string is zero-terminated array of characters (find char with value 0 at end);
void to_lower(char* s)
{
    while (*s != 0) {
        if (*s >= minVal && *s <= maxVal) {
            *s += 32;
        }
        // increment pointer value
        ++s;
    }
}

int main()
{
    cout<< "a: " << (int) a << ", z: " << int (z) << endl;
    cout<< "A: " << (int) minVal << ", Z: " << int (maxVal) << endl;
    char *testString = new char[14] {'H', 'e', 'l', 'l', 'o', ',', ' ', 'W', 'o', 'r', 'l', 'd', '!', 0};
    to_lower(testString);
    cout << "After: " << testString << endl;
    return 0;
}
