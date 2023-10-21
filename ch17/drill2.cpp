#include "std_lib_facilities.h"


int main() {
    int x = 7;
    int *p1 = &x;
    cout << "p1: " << p1 << ", x: " << x << endl;
    int *p2 = new int[7] {1, 2, 4, 8, 16, 32, 64};
    cout << "p2: " << p2 << ", p2*: " << *p2 << endl;
    int *p3 = p2;
    p2 = p1;
    p2 = p3;
    cout << "p1: " << p1 << ", *p1: " << *p1 << endl;
    cout << "p2: " << p2 << ", *p2: " << *p2 << endl;
    // NB: p1 doesn't need deleting since no memory was dynamically allocated (just copied address of int object 'x')
    delete[] p2;
    p1 = new int[10] {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
    p2 = new int[10];
    for (int i = 0; i < 10; ++i) {
        p2[i] = p1[i];
        cout << "p2[" << i <<"] is now: " << p2[i] << endl;
    }

}
