#include "std_lib_facilities.h"

template<typename T> 
void f1(vector<T>& v1, vector<T>& v2) {
    if (v1.size() != v2.size()) {
        error("Size of vectors not equal");
    }
    for (int i = 0; i < v2.size(); ++i) {
        v1[i] += v2[i];
    }
}

template<typename Number> 
Number f2(vector<Number>& vt, vector<Number>& vu) {
    Number res;
    if (vt.size() != vu.size()) {
        error("Size of vectors not equal");
    }
    for (int i = 0; i < vt.size(); ++i) {
        res += vt[i]*vu[i];
    }
    return res;
}

int main()
{
    vector<int> vi1 = {1, 2, 3, 4, 5, 6};
    vector<int> vi2 = {1, 2, 3, 4, 5, 6};
    f1(vi1, vi2);

    cout << "Result:\n";
    for (int x : vi1) {
        cout << x << endl;
    }

    vector<string> vs1 = {"Hello", "Cat"};
    vector<string> vs2 = {"World", "Dog"};
    f1(vs1, vs2);
    cout << "Result:\n";
    for (string x : vs1) {
        cout << x << endl;
    }

    cout << "Result: " << f2(vi2, vi2) << endl;
}
