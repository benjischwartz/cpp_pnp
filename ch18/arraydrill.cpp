#include "std_lib_facilities.h"

int ga[10] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

void f(int a[], int n);

int main() 
{
    f(ga, 10);
    int aa[10];
    for (int i = 0; i < 10; ++i) {
        // define aa with first 10 factorial values
        int val = 1;
        for (int j = i + 1; j > 0; --j) {
            val *= j;            
        }
        aa[i] = val;
    }
    f(aa, 10);
    return 0;
}

void f(int a[], int n)
{
    int la[10];
    // copy values from ga into la
    for (int i = 0; i < 10; ++i) {
        la[i] = ga[i];
    }
    // print out elements of la
    for (int i = 0; i < 10; ++i) {
        cout<<"la["<<i<<"]: "<<la[i]<<endl;
    }
    // define free-store array
    int* p = new int[n];
    for (int i = 0; i < n; ++i) {
        p[i] = a[i];
    }
    // print out elements of free-store array
    for (int i = 0; i < n; ++i) {
        cout<<"p["<<i<<"]: "<<p[i]<<endl;
    }
}
