#include "Patron.h"


// constructors
Patron::Patron(string un, int ln, double lf)    // Check for valid entry and initialise
    : user_name(un), libcard_number(ln), library_fees(lf) 
{
}

const Patron& default_patron();

Patron::Patron()
    :user_name(default_patron().get_user_name()),
    libcard_number(default_patron().get_libcard_number()),
    library_fees(default_patron().get_library_fees()) 
{
}

const Patron& default_patron()
{
    static const Patron pp("John Doe", 8888, 0.0);
    return pp;
}

// helper functions etc.

bool owes_fee(const Patron& p) { return (p.get_library_fees() > 0); }

bool operator==(const Patron& a, const Patron& b)
{
    return (strcmp(a.get_user_name().c_str(), b.get_user_name().c_str()) == 0)
        && a.get_libcard_number() == b.get_libcard_number();
} 

bool operator!=(const Patron& a, const Patron& b)
{
    return !(a==b);
}
