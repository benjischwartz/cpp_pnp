#include <iostream>

using namespace std;

struct myStruct
{
    int i; 
    double d;
    char c;
};

class myClass
{
public:
    int get_int() { return i; }
    double get_double() { return d; }
    char get_char() { return c; }
private:
    int i;
    double d;
    char c;
};

void sizes(char ch, int i, int* p1, bool b, double d, double* p2, string str, myStruct s, myClass c)
{
    cout<<"the size of char is "<<sizeof(char)<<' '<<sizeof(ch)<<endl;
    cout<<"the size of int is "<<sizeof(int)<<' '<<sizeof(i)<<endl;
    cout<<"the size of int* is "<<sizeof(int*)<<' '<<sizeof(p1)<<endl;
    cout<<"the size of bool is "<<sizeof(bool)<<' '<<sizeof(b)<<endl;
    cout<<"the size of double is "<<sizeof(double)<<' '<<sizeof(d)<<endl;
    cout<<"the size of double* is "<<sizeof(double*)<<' '<<sizeof(p2)<<endl;
    cout<<"the size of string is "<<sizeof(string)<<' '<<sizeof(str)<<endl;
    cout<<"the size of myStruct is "<<sizeof(myStruct)<<' '<<sizeof(s)<<endl;
    cout<<"the size of myClass is "<<sizeof(myClass)<<' '<<sizeof(c)<<endl;
}

int main()
{
    int i = 0;
    int* p1 = &i;
    double d = 3.1415;
    double* p2 = &d;
    string str = "Hello World!\n";
    myStruct s = myStruct {};
    myClass c = myClass {};
    sizes('a', i, p1, true, d, p2, str, s, c);
    cout<<endl;
    int *p = new int[2];
    cout<<"Out of range elem: "<<p[5000]<<endl;
    cout<<"Out of range elem: "<<p[-5]<<endl;
    return 0;
}
