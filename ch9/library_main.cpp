#include "Library.h"

int main()
{
    // Create some books
    Book defBook = Book();
    Chrono::Date defDate = Chrono::Date();
    Book mobyDick = Book("1-2-3-4", "Moby Dick", "Herman Melville", string_to_genre("fiction"), defDate, false);
    Book mozart = Book("6-7-4-a", "Mozart in Italy", "Jane Glover", string_to_genre("biography"), defDate, false);
    Book partyLines = Book("1-5-3-x", "Party Lines", "Ed Gillett", string_to_genre("periodical"), defDate, false);
    Book dummyBook = Book("1-4-3-q", "Dummy Book", "Dummy Author", string_to_genre("children"), defDate, false);

    // Create some patrons
    Patron defPatron {};
    Patron james {"James Glover", 4848, 0.0};
    Patron fred {"Fred Smith", 1413, 10.80};
    Patron albert {"Albert Jones", 7823, 3.50};
    Patron jack {"Jack Hughes", 5484, 0.0};
    Patron tony {"Tony Barrett", 4832, 60.90};

    // Add books and patrons to library
    Library lib;

    lib.add_book(defBook);
    lib.add_book(mobyDick);
    lib.add_book(mozart);
    lib.add_book(partyLines);

    lib.add_patron(james);
    lib.add_patron(fred);
    lib.add_patron(albert);
    lib.add_patron(jack);

    // Check out some books, (provide patron and book)
    lib.check_out_book(mobyDick, james);
    lib.check_out_book(partyLines, jack);

    // Show patrons owing money
    vector<string> patronsOwing = lib.patrons_owing();
    cout << "Patrons owing money:\n";
    for (string p : patronsOwing) {
        cout << p << endl;
    }

    // Show list of transactions
    vector<Transaction> transactions = lib.get_transactions();
    cout << "Transactions:\n";
    for (Transaction t : transactions) {
        cout << "Book: " << t.book << endl;
        cout << "Patron: " << t.patron.get_user_name() << endl; 
        cout << "Date: " << t.date << endl; 
        cout << endl;
    }
}
