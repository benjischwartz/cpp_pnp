#include "std_lib_facilities.h"

// Template class that can hold a pair of values of any type
template<typename T> 
class Pair {
public:
    // constructor
    Pair(T k, T v) : key{k}, value{v} {}

    // const functions
    T get_key() const { return key; }
    T get_value() const { return value; }
    
    void set_value(T v) { value = v; }
private:
    T key;
    T value;
};

template<typename T> 
T get_value(T k, vector<Pair<T>>& var_table)
{
    for (Pair<T>& t : var_table) {
        if (t.get_key() == k) return t.get_value();
    }
    error("get: undefined variable ", k);
    return k;
}

template<typename T> 
void set_value(T k, T v, vector<Pair<T>>& var_table)
{
    for (Pair<T>& t : var_table) {
        if (t.get_key() == k) t.set_value(v);
    }
    Pair<T> p = {k, v};
    var_table.push_back(p);
}

template<typename T> 
void print_table(vector<Pair<T>>& var_table) 
{
    for (Pair<T>& t : var_table) {
        cout << '{' << t.get_key() << ", " 
             << t.get_value() << '}' << endl;
    }
}

int main() 
{
    vector<Pair<string>> str_table;
    vector<Pair<int>> int_table;
    vector<Pair<double>> double_table;
    vector<Pair<char>> char_table;
    set_value(std::string("Hello"), std::string("World"), str_table);
    set_value(std::string("Cat"), std::string("Dog"), str_table);
    set_value(420, 69, int_table);
    set_value(12.3, 14.5, double_table);
    set_value('x', 'u', char_table);
    cout << "Testing:\n";
    print_table(str_table);
    print_table(int_table);
    print_table(double_table);
    cout << "Value for key = Hello: " << get_value(std::string("Hello"), str_table) << endl;
    cout << "Value for key = 420: " << get_value(420, int_table) << endl;
    cout << "Value for key = 12.3: " << get_value(12.3, double_table) << endl;
    cout << "Value for key = x: " << get_value('x', char_table) << endl;
    
}
