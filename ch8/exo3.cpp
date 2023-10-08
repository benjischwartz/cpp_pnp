#include "std_lib_facilities.h"

void print(vector<int>& v, string& s);
void fibonacci(int x, int y, vector<int>& v, int n);
int main() {
    vector<int> v;
    int current;
    string vectorName;
    cout<<"Please enter the name of the vector:\n";
    cin >> vectorName;
    cout<<"Please enter some integers followed by CTRL+D\n";
    while (cin>>current) {
        v.push_back(current);
    }
    print(v, vectorName);
    return 0;
}


void print(vector<int>& v, string& s) {
    cout << s << ":\n";
    for (int x : v) {
        cout<<x<<endl;
    }
}

void fibonacci(int x, int y, vector<int>& v, int n) {
    // Error if n < 2
    if (n < 2 || x < 1 || y < 1) { error("Number of Fibonacci sequence less than 2 and start with integers larger than 1");}
    v.push_back(x);
    v.push_back(y);
    for (int i = 2; i < n; ++i) {
        v.push_back(v[i-2] + v[i-1]);
    }
}
