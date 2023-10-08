#include "std_lib_facilities.h"
#include "Book.h"
#include "Patron.h"

struct Transaction {
    Book book;
    Patron patron;
    Chrono::Date date;
};

class Library {
public:

    // default constructor
    //Library();

    //nonmodifying functions
    vector<string> patrons_owing();
    vector<Transaction> get_transactions() { return transactions; }
    bool have_book(Book book);
    bool have_patron(Patron patron);

    // modifying functions
    void add_book(Book b) { books.push_back(b); }
    void add_patron(Patron p) { patrons.push_back(p); }
    void add_transaction(Transaction t) { transactions.push_back(t); }
    void check_out_book(Book book, Patron patron);
private:
    vector<Book> books;
    vector<Patron> patrons;
    vector<Transaction> transactions;
};
