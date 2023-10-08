#include "std_lib_facilities.h"

double ctok(double c)
{
    double k = c + 273.15;
    if (k < 0) error("Temperature below absolute zero in ctok()");
    return k;
}

double ktoc(double k)
{
    double c = k - 273.15;
    if (c < -273.15) error("Temperature below absolute zero in ktoc()");
    return c;
}

int main() 
try {
    double input = 0;
    char unit = 'x';
    cout << "Enter a temperature followed by a unit (c or k):\n";
    cin >> input >> unit;
    switch(unit) {
        case('c'):
            cout<<ctok(input)<<" k \n";
            break;
        case('k'):
            cout<<ktoc(input)<<" c \n";
            break;
        default:
            error("Invalid unit entered. Please enter in the form \"temperature unit\"");
            break;
    }
    return 0;
}
catch (exception& e) {
    cerr<<"error: "<<e.what()<<'\n';
    keep_window_open();
    return 1;
}
catch(...) {
    cerr<<"Oops: unkown exception!\n";
    keep_window_open();
    return 2;
}
