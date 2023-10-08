#include "std_lib_facilities.h"

void print(vector<int>& v, string& s);
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
