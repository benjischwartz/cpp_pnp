#include "std_lib_facilities.h"

// Ask the user for input N. 
// Read and store a series of integers
// Compute the sum of the first N integers.

// Helper function
int sum_values(int n, vector<int> values);
int main()
try {

    int num_to_sum;
    vector<int> values;

    cout<<"Please enter the number of values you want to sum:\n";
    cin>>num_to_sum;

    fflush(stdin);
    cout<<"Please enter some integers (press '|' to stop):";

    for(int value; cin>>value;) {
        values.push_back(value);
    } 
    fflush(stdin);

    int sum = sum_values(num_to_sum, values);
    cout<<"The sum of the first "<<num_to_sum<<" values is "<<sum<<".\n";
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

int sum_values(int n, vector<int> values)
{
    if (n < 0 || n > values.size()) error("Unsuitable number of values to sum in sum_values()");
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += values[i];
    }
    return sum;
}

