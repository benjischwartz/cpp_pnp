#include "std_lib_facilities.h"

struct God {
    string name;
    string mythology;
    string vehicle;
    string weapon;
};

class Link {
public:
    string value;
    God god;
    Link(const string& v, const God& g, Link* p = nullptr, Link* s = nullptr)
        : value{v}, god{g}, prev{p}, succ{s} {}
    Link* insert(Link *n);              // insert n before this object
    Link* add(Link *n);                 // insert n after this object
    Link* add_ordered(Link* n);         // insert n in correct lexicographical position
    Link* erase();
    Link* find(const string& s);        // find s in list
    // const Link* find(const string& s) const;    // find s in const list
    Link* advance(int n) const;         // move n positions in list
    Link* next() const { return succ; }
    Link* previous() const { return prev; }
private:
    Link* prev;
    Link* succ;
};
