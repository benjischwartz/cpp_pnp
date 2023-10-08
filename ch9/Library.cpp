#include "Library.h"

bool Library::have_book(Book book) {
    for (Book b : books) {
        if (b == book) return true;
    }
    return false;
}

bool Library::have_patron(Patron patron) {
    for (Patron p : patrons) {
        if (p == patron) return true;
    }
    return false;
}
// Check both the user and the book are in the library.
//      If not, report an error.
// Check to make sure user owes no fees. 
//      If they do, report an error.
// Create a Transaction, and place it in transactions.
void Library::check_out_book(Book book, Patron patron) {
    if (!have_book(book)) error ("Library does not have this book");
    if (!have_patron(patron)) error ("Library does not have patron");
    if (owes_fee(patron)) error ("Patron owes fees");
    Chrono::Date dd;
    Transaction t = {book, patron, dd};
    add_transaction(t);
}

// Returns a vector containing names of all Patrons who owe fees.
vector<string> Library::patrons_owing() {
    vector<string> v;
    for (Patron p : patrons) {
        if (owes_fee(p)) { v.push_back(p.get_user_name()); }
    }
    return v;
}

