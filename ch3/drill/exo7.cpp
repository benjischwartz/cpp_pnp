#include "std_lib_facilities.h"

int main()
{
    string str1, str2, str3 {""};
    cout << "Please enter three strings:\n";
    cin >> str1 >> str2 >> str3;
    if (str1 > str2 && str1 > str3) {
        if (str2 >= str3) {
            cout << str3 << ", " << str2 << ", " << str1;
        }
        else {
            cout << str2 << ", " << str3 << ", " << str1;
        }
    }
    else if (str2 > str1 && str2 > str3) {
        if (str1 >= str3) {
            cout << str3 << ", " << str1 << ", " << str2;
        }
        else {
            cout << str1 << ", " << str3 << ", " << str2;
        }
    }
    else {
        if (str1 >= str2) {
            cout << str2 << ", " << str1 << ", " << str3;
        }
        else {
            cout << str1 << ", " << str2 << ", " << str3;
        }
    }
    cout << '\n';
}
