#include "std_lib_facilities.h"

int main() {
    cout<<"Please enter your first name and age\n";
    string first_name = "???";
    double age_years, age_months = 0;
    cin >> first_name >> age_years;
    age_months = age_years * 12;
    cout << "Hello, " << first_name << " (age " << age_years << " years, which is " << age_months << " months)\n";
    return 0;
}
