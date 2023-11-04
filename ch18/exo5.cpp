#include "std_lib_facilities.h"

// function that concatenates two strings with a dot in between
string cat_dot(const string& s1, const string& s2, const string& sep)
{
    return s1 + sep + s2;
}

// version which returns a free-store-allocated C-style string as result.
// Free memory allocated from free store.
char* cat_dot2(const string& s1, const string& s2, const string& sep)
{

    int n1 = 0;
    while (s1[n1]) ++n1;
    int n2 = 0;
    while (s2[n2]) ++n2;
    int n3 = n1 + 1 + n2 + 1;
    char* res = new char[n3];

    int i = 0;
    int j = 0;
    cout << "i is: "<<i<<endl;
    while(s1[j]) {
        res[i] = s1[j];
        cout<<"copying %c: " << res[i] << endl;
        ++i;
        ++j;
    }
    j = 0;
    while(sep[j]) {
        res[i] = sep[j];
        cout<<"copying %c: " << res[i] << endl;
        ++i;
        ++j;
    }
    j = 0;
    while(s2[j]) {
        res[i] = s2[j];
        cout<<"copying %c: " << res[i] << endl;
        ++i;
        ++j;
    }
    res[i] = 0;
    return res;
}

int main()
{
    cout << cat_dot("Niels", "Bohr", "...")<<endl;
    char* alloc_string = cat_dot2("Niels", "Bohr", "...");
    cout << alloc_string << endl;
    delete[] alloc_string;
}
