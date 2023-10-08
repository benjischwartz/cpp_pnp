#include "std_lib_facilities.h"

// Read a sequence of doubles into a fector. compute and print the sum of all distances.
// Find and print the smallest and greatest distance between two neighbouring cities.
// Find and print the mean distance between two neighbouring cities.
int main() {
    vector<double> distances;
    double min = std::numeric_limits<int>::max();
    double max = 0;
    double sum = 0;
    for (double distance; cin>>distance;) {
        // update min and max
        min = distance < min ? distance : min;
        max = distance > max ? distance : max;      
        sum += distance; 

        // add to vector
        distances.push_back(distance);
    }
    cout << "Sum is " << sum << '\n';
    cout << "Min is " << min << '\n';
    cout << "Max is " << max << '\n';
    cout << "Mean is " << sum/distances.size() << '\n';
}
