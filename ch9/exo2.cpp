// Design and implement a Name_pairs class
// (name, age) => name is string, age is double
// Use vector<string> name and vector<double> age
// Provide input operation read_names() thar reads a series of names.
// Provide a read_ages() operation that promps user for age for each name.
// Provide a print() operation that prints out the (name[i], age[i]) pairs 
//      (one per line), determined by name vector.
// Provide a sort() operation thatsorts the name vector in alphabetical 
//      order and reorganizes the age vector to match.
// Implement all "operations" as member functions.

#include "exo2.h"

namespace NamePairs {
// member function definitions:

void Name_pairs::read_names() 
{
    cout << "Enter a list of names. Type '.' to stop.\n";
    string newName;
    cin >> newName;
    while (newName != ".") {
        name.push_back(newName);
        cin >> newName;
    }
}

void Name_pairs::read_ages() 
{
    cout << "Enter an age for each person.\n";
    double newAge;
    for (string n : name) {
        cout << n << ": ";
        cin >> newAge;
        age.push_back(newAge);
        cout << endl;
    }
}

void Name_pairs::print() const
{
    if (name.size() != age.size()) throw Invalid{};
    for (int i = 0; i < name.size(); ++i) {
        cout << name[i] << ", " << age[i] << endl;
    }    
}

void Name_pairs::sort()
{
    if (name.size() != age.size()) throw Invalid{};

    // copy name and age vectors to sort age vector later
    vector<string> nameTemp = name;
    vector<double> ageTemp = age;

    std::sort(name.begin(), name.end());
    int j = 0;
    for (string s: name) {
        for (int i = 0; i < nameTemp.size(); ++i) {
            if (strcmp(nameTemp[i].c_str(),s.c_str()) == 0) {
                age[j] = ageTemp[i];
                ++j;
                break;
            }
        }
    }
}
// helper functions

bool operator==(const Name_pairs& a, const Name_pairs& b)
{
    if (a.name_length() != b.name_length() ||
            a.name_length() != a.age_length() ||
            b.name_length() != b.age_length()) { return false; }
    vector<string> aName = a.get_name();
    vector<string> bName = b.get_name();
    vector<double> aAge = a.get_age();
    vector<double> bAge = b.get_age();
    for (int i = 0; i < a.name_length(); ++i) {
        if (aName[i] != bName[i] || aAge[i] != bAge[i]) return false;
    } 
    return true;
}

bool operator!=(const Name_pairs& a, const Name_pairs& b)
{
    return !(a==b);
}

ostream& operator<<(ostream& os, const Name_pairs& np)
{
    if (np.name_length() != np.age_length()) error("lengths don't match");
    vector<string> npName = np.get_name();
    vector<double> npAge = np.get_age();
    for (int i = 0; i < np.name_length(); ++i) {
        os << npName[i] << ", " << npAge[i] << endl;
    }    
    return os;
}

} // end NamePairs namespace
