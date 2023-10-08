#include "std_lib_facilities.h"

int main()
{
    int max = 100;
    int min = 0;
    char response = 'a';
    while (min < (max - 1)) {
        cout << "Is the number you are thinking of less than " << (min+max)/2 << "? Respond with y/n.\n";
        cin >> response;
        switch(response) {
            case 'y':
                max = (min+max)/2;
                break;
            case 'n':
                min = (min+max)/2;
                break;
            default:
                cout << "Please enter a valid response.\n";
                break;
        }

    }
    cout << "Your number is " << min << "!\n";
    return 0;
}
