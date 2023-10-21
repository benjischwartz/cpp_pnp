#include "std_lib_facilities.h"

// print out values of a to os
void print_array10(ostream& os, int* a) {
    for (int i = 0; i < 10; ++i) {
        os << "Element " << i + 1 << ": " << v1[i] << endl;
    }
}


int main()
{
    // Allocate an array of ten ints on the free store using new
    int *v1 = new int[10];

    // Print to cout
    for (int i = 0; i < 10; ++i) {
        cout << "Element " << i + 1 << ": " << v1[i] << endl;
    }

    // Print to cout using print_array10
    print_array10(cout, v1);

    // Deallocate using delete[]
    delete[] v1;

}
