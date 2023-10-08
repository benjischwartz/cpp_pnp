#include "Book.h"
#include <regex>

// member function definitions:

Book::Book(string ii, string tt, string aa, Genre gg, Chrono::Date cc, bool co)    // Check for valid entry and initialise
    : ISBN(ii), title(tt), author(aa), genre(gg), copyright_date(cc), checked_out(co)
{
    if (!is_ISBN(ii)) throw Invalid();
}

const Book& default_book();

Book::Book()
    :ISBN(default_book().get_ISBN()),
    title(default_book().get_title()),
    author(default_book().get_author()),
    genre(default_book().get_genre()),
    copyright_date(default_book().get_copyright_date()),
    checked_out(false)
{
}

// helper functions etc.

const Book& default_book()
{
    // Uses default constructor for Date()
    Chrono::Date dd;
    static const Book bb("0-0-0-0", "Default Title", "Default Author", Genre::fiction, dd, false);
    return bb;
}

// check ISBN is in form n-n-n-x
bool is_ISBN(string ISBN)
{
    regex r ("[0-9]-[0-9]-[0-9]-[a-z0-9]");
    if (regex_match(ISBN, r)) { return true; }
    return false;
}

string genre_to_string(Genre g) {
    switch(g) {
        case Genre::fiction:
            return "fiction";
        case Genre::nonfiction:
            return "nonfiction";
        case Genre::periodical:
            return "periodical";
        case Genre::biography:
            return "biography";
        case Genre::children:
            return "children";
        default:
            return "";
    }
}

Genre string_to_genre(string s) {
    if(strcmp("fiction", s.c_str()) == 0)
        return Genre::fiction;
    else if(strcmp("nonfiction", s.c_str()) == 0)
        return Genre::nonfiction;
    else if(strcmp("periodical", s.c_str()) == 0)
        return Genre::periodical;
    else if(strcmp("biography", s.c_str()) == 0)
        return Genre::biography;
    else if(strcmp("children", s.c_str()) == 0)
        return Genre::children;
    else
        return Genre::fiction;
}

// Check if ISBN numbers are the same
bool operator==(const Book& a, const Book& b) {
    return (a.get_ISBN() == b.get_ISBN());
}
bool operator!=(const Book& a, const Book& b) {
    return !(a == b);
}

ostream& operator<<(ostream& os, const Book& b) {
    return os << b.get_title() << '\n'
                << b.get_author() << '\n'
                << b.get_ISBN() << '\n';
}
