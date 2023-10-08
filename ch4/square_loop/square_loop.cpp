#include "std_lib_facilities.h"

// function declaration
int square(int x); 

int main()
{
    for (int i = 0; i < 100; ++i) {
        cout<<i<<'\t'<<square(i)<<'\n';
    }
}

// function definition
int square(int x) {
    int res = 0;
    for (int i = 0; i < x; ++i) {
        res += x;
    }
    return res;
}
