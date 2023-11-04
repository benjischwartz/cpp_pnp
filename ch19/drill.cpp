#include "std_lib_facilities.h"

template<typename T> 
class S 
{ 
public:
    // Construct S with a T
    S(T v) :val{v} {}
    T& get();
    const T& get() const;
    void set(T v);
    S& operator=(const T&); // copy assignment
private:
    T val;
};

// Definition outside of class
template<typename T>
T& S<T>::get() { return val; }

template<typename T>
const T& S<T>::get() const { return val; }

template<typename T>
void S<T>::set(T v) { val = v; }

template<typename T>
S<T>& S<T>::operator=(const T& t)
{
    if (val==&t) return *this;  // self-assignment, no work needed
    val = t;                    // set value of val
    return *this;               // return a self-reference
}

template<typename T>
void read_val(T& v)       // reads from cin into v.
{
    cin >> v;
}

template<typename T>
ostream& operator<<(ostream& os, S<T> s)
{
    os << s.get();
    return os;
}

// Define output operator for vector<T>s 
template<typename T>
ostream& operator<<(ostream& os, S<vector<T>> s)
{
    os<<"{ ";
    vector<T> v = s.get();
    for (T t : v) { os << t << ", "; }
    os << "\b\b}";
    return os;
}


int main()
{
    S<int> s_i(10);
    S<char> s_c('a') ;
    S<double> s_d(10.5);
    S<string> s_str("Hello World!");
    S<vector<int>> s_v({1, 2, 3, 4, 5});
    cout << "s_i val: " << s_i.get() << endl;
    cout << "s_c val: " << s_c.get() << endl;
    cout << "s_d val: " << s_d.get() << endl;
    cout << "s_str val: " << s_str.get() << endl;
    cout << "s_v vals:\n";
    for (int x : s_v.get()) { cout << x << endl; }

    // Use read_val to read into variables
    cout << "Testing set():\n";
    s_c.set('z');
    cout << "new s_c val: " << s_c.get() << endl;

    cout << "Testing copy assignment:\n";
    S<int> s_i2(20);
    s_i = s_i2;
    cout << "new s_i val: " << s_i.get() << endl;

    cout<< "Testing read_val():\n";
    int i;
    char c;
    double d;
    string str;
    cout<< "Enter an integer: ";
    read_val(i);
    cout<< "Enter a character: ";
    read_val(c);
    cout<< "Enter a double: ";
    read_val(d);
    cout<< "Enter a string: ";
    read_val(str);
    s_i.set(i);
    s_c.set(c);
    s_d.set(d);
    s_str.set(str);
    cout << "s_i val: " << s_i.get() << endl;
    cout << "s_c val: " << s_c.get() << endl;
    cout << "s_d val: " << s_d.get() << endl;
    cout << "s_str val: " << s_str.get() << endl;

    cout << "Testing output operator:\n";
    cout << s_i << endl << s_c << endl << s_d << endl << s_str << endl;
    cout << s_v << endl;
}
