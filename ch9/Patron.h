// Header only 
#include "std_lib_facilities.h"


class Patron {
public:

    // constructors
    Patron(string un, int ln, double lf);    // Check for valid entry and initialise
    Patron();   // default

    // nonmodifying functions
    string get_user_name() const { return user_name; }
    int get_libcard_number() const { return libcard_number; }
    double get_library_fees() const { return library_fees; }

    // modifying functions
    void set_library_fees(double fee) { library_fees = fee; }

private:
    string user_name;
    int libcard_number;
    double library_fees;
};



bool owes_fee(const Patron& p);

bool operator==(const Patron& a, const Patron& b);
bool operator!=(const Patron& a, const Patron& b);
