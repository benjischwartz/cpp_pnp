#include "std_lib_facilities.h"

int main() {
    constexpr double y_to_aud {0.011};
    constexpr double k_to_aud {0.14};
    constexpr double p_to_aud {1.96};
    double value {0};
    char currency {'x'};
    cout<<"Please enter a value followed by a currency (yen 'y', kroner 'k', or pounds 'p'):\n";
    cin>>value>>currency;
    cout<<"currency is: "<<currency<<'\n';
    cout<<"value is: "<<value<<'\n';
    switch(currency) {
        case 'y':
            cout << value << "y == " << y_to_aud*value << "aud\n";
            break;
        case 'k':
            cout << value << "k == " << k_to_aud*value << "aud\n";
            break;
        case 'p':
            cout << value << "p == " << p_to_aud*value << "aud\n";
            break;
        default:
            cout << "Sorry, I don't know a currency called '" << currency << "'\n";
            break;
    }
    return 0;
}
