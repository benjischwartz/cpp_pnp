#include "std_lib_facilities.h"

int main()
{
    double x1, x2 = 0;
    while (cin>>x1>>x2) {
        if (x1 == x2) {
            cout << "The numbers are equal.\n";
        } else {
            double max = x1 > x2 ? x1 : x2;
            double min = x1 > x2 ? x2 : x1;
            cout << "The smaller value is "<< min << ". The larger value is " << max << ".\n";
            if ((max-min) < 1.0/100) {
                cout << "The numbers are almost equal.\n";
            }
        }
        fflush(stdin);
    }
    return 0;
}
