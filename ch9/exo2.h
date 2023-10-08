// Design and implement a Name_pairs class
// (name, age) => name is string, age is double
// Use vector<string> name and vector<double> age
// Provide input operation read_names() thar reads a series of names.
// Provide a read_ages() operation that promps user for age for each name.
// Provide a print() operation that prints out the (name[i], age[i]) pairs 
//      (one per line), determined by name vector.
// Provide a sort() operation that sorts the name vector in alphabetical 
//      order and reorganizes the age vector to match.
// Implement all "operations" as member functions.


#include "std_lib_facilities.h"

namespace NamePairs {

class Name_pairs {
public:
    class Invalid {};       // to throw as exception
                            
    // modifying operations
    void read_names();
    void read_ages();
    void sort();

    // nonmodifying operations:
    void print() const;
    vector<string> get_name() const { return name; }
    vector<double> get_age() const { return age; }
    int name_length() const { return name.size(); }
    int age_length() const { return age.size(); }

private:
    vector<string> name;
    vector<double> age;
};

bool operator==(const Name_pairs& a, const Name_pairs& b);
bool operator!=(const Name_pairs& a, const Name_pairs& b);

ostream& operator<<(ostream& os, const Name_pairs& np);
} // NamePairs
