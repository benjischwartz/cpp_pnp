#include "std_lib_facilities.h"

vector<int> gv {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

void f(vector<int> v);

int main()
{
    f(gv);
    vector<int> vv;
    for (int i = 0; i < 10; ++i) {
        // define vv with first 10 factorial values
        int val = 1;
        for (int j = i + 1; j > 0; --j) {
            val *= j;            
        }
        vv.push_back(val);
    }
    f(vv);
    return 0;
}

void f(vector<int> v)
{
    // define local vector with same num elems as argument vector
    vector<int> lv(v.size());
    // copy values from gv into lv
    for (int i = 0; i < v.size(); ++i) {
        lv[i] = gv[i];
    }
    // print out elems of lv
    for (int i = 0; i < v.size(); ++i) {
        cout << "lv["<<i<<"]: "<<lv[i]<<endl;
    }
    // initialise local vector to be a copy of argument vector
    vector<int> lv2 = v;
    // print out elems of lv2
    for (int i = 0; i < lv2.size(); ++i) {
        cout << "lv2["<<i<<"]: "<<lv2[i]<<endl;
    }
}
