#include "std_lib_facilities.h"

// Program to solve quadratic equations.
// Use doubles for the user inputs for a, b, and c. 
// Output both x1 and x2. 

int main()
{
    double a, b, c, x1, x2 = 0;
    cout << "Enter a, b and c for the polynomial:\n";
    cin >> a >> b >> c;
    x1 = (-b + sqrt(b*b-4*a*c))/(2*a);
    x2 = (-b - sqrt(b*b-4*a*c))/(2*a);
    cout << "x1 is " << x1 << ", x2 is " << x2 << "\n";
    return 0;
}
