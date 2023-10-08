#include "std_lib_facilities.h"

int main()
{
    string current;
    string previous;
    int counter = 0;
    while (cin >> current) {
        if (current == previous) {
            cout << "Repeated word: " << current << " which was word number " << counter << '\n';
            return 0;
        }
        previous = current;
        counter++;
    }
    return 0;
}
