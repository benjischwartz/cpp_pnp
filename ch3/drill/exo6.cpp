#include "std_lib_facilities.h"

int main()
{
    int int1, int2, int3 {0};
    cout << "Please enter three integer values:\n";
    cin >> int1 >> int2 >> int3;
    if (int1 > int2 && int1 > int3) {
        if (int2 >= int3) {
            cout << int3 << ", " << int2 << ", " << int1;
        }
        else {
            cout << int2 << ", " << int3 << ", " << int1;
        }
    }
    else if (int2 > int1 && int2 > int3) {
        if (int1 >= int3) {
            cout << int3 << ", " << int1 << ", " << int2;
        }
        else {
            cout << int1 << ", " << int3 << ", " << int2;
        }
    }
    else {
        if (int1 >= int2) {
            cout << int2 << ", " << int1 << ", " << int3;
        }
        else {
            cout << int1 << ", " << int2 << ", " << int3;
        }
    }
    cout << '\n';
}
