#include "std_lib_facilities.h"

int main() {
    while (true) {
        int *x = new int[1000000000000];
        cout << "Allocating at address: " << x << endl;
    }
}
