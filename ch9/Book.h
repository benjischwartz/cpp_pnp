// Book class, such as part of software for a library
// Should have members for ISBN, title, author and copyright date
// Store data on whether or not the book is checked out.
// Create functions for returning data values.
// Create functions for checking a book in or out.
// Do simple validation of data entered into a Book
//      --> accept ISBNs only of form n-n-n-x (n is int, x is char)
//      --> store ISBN as string

#include "std_lib_facilities.h"
#include "Chrono.h"

enum class Genre {
    fiction, nonfiction, periodical, biography, children
};

class Book {
public:

    class Invalid {};                                           // To throw as exceptions
                                                                
    Book(string ii, string tt, string aa, Genre gg, Chrono::Date cc, bool co);    // Check for valid entry and initialise
    Book();                                                     // default constructor

    // non-modifying operations
    bool get_checked_out() const { return checked_out; }
    string get_ISBN() const { return ISBN; }
    string get_title() const { return title; }
    string get_author() const { return author; }
    Genre get_genre() const { return genre; }
    Chrono::Date get_copyright_date() const { return copyright_date; }

    // modifying operations
    void check_out(bool t) { checked_out = t;}

private:
    string ISBN;
    string title;
    string author;
    Genre genre;
    Chrono::Date copyright_date;
    bool checked_out;
};


// helper functions etc.
const Book& default_book();

// check ISBN is in form n-n-n-x
bool is_ISBN(string ISBN);

const Book& default_book();

string genre_to_string(Genre g);
Genre string_to_genre(string s);

bool operator==(const Book& a, const Book& b);
bool operator!=(const Book& a, const Book& b);
ostream& operator<<(ostream& os, const Book& b);
