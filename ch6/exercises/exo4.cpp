#include "std_lib_facilities.h"

// reworking ch4 exo19
//
// Enter a set of name-and-value pairs, terminate input with NoName 0.
// Check each name is unique and terminate with an error if a name is entered twice. 
// Write out all the (name, value) pairs, one per line.

class Name_value {
    public:
        string name;
        double value;
        Name_value():name{""},value{0.0} {}                     // construct from empty
        Name_value(string n, double v):name{n},value{v} {}      // construct from string, value
};

void check_unique(vector<Name_value> name_values, string name);
void print_name_values(vector<Name_value> name_values);

int main() 
try {
    vector<Name_value> name_values;
    double value;
    string name;
    while (cin>>name>>value) {
        if (name == "NoName" && value == 0) {
            break;
        }
        check_unique(name_values, name);
        Name_value new_name_value = Name_value(name, value);
        name_values.push_back(new_name_value);        
    }
    print_name_values(name_values);
    keep_window_open();
    return 0;
}
catch(exception& e) {
    cerr << "error: " << e.what() <<'\n';
    keep_window_open();
    return 1;
}
catch(...){
    cerr << "Oops: unknown exception!\n";
    keep_window_open();
    return 2;
}

void check_unique(vector<Name_value> name_values, string name)
{
    for (Name_value nv:name_values) {if (nv.name == name) error("in check_unique(): name is not unique!");}
}

void  print_name_values(vector<Name_value> name_values)
{
    for(Name_value nv:name_values) {
        cout<<nv.name<<'\t'<<nv.value<<'\n';
    }
}
