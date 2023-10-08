#include "std_lib_facilities.h"
#include "Book.h"


int main()
{
    Book b;
    try {
        cout<<"Default Book:\n";
        cout<<"ISBN: "<<b.get_ISBN()<<endl;
        cout<<"title: "<<b.get_title()<<endl;
        cout<<"author: "<<b.get_author()<<endl;
        cout<<"genre: "<<genre_to_string(b.get_genre())<<endl;
        cout<<"copyright date: "<<b.get_copyright_date()<<endl;
        cout<<"checked out: "<<b.get_checked_out()<<endl;

        string ISBN, title, author, genre_str;
        Genre genre;
        bool checked_out;
        Chrono::Date dd;
        cout<<"Please enter book details:\n";
        cout<<"ISBN: "; std::getline(cin, ISBN);
        cout<<"title: "; std::getline(cin, title);
        cout<<"author: "; std::getline(cin, author);
        cout<<"genre: "; std::getline(cin, genre_str); genre = string_to_genre(genre_str);
        cout<<"checked out: "; cin >> checked_out;
        Book b2 {ISBN, title, author, genre, dd, checked_out};
        cout << "\nNew Book:\n";
        cout<<"ISBN: "<<b2.get_ISBN()<<endl;
        cout<<"title: "<<b2.get_title()<<endl;
        cout<<"author: "<<b2.get_author()<<endl;
        cout<<"genre: "<<genre_to_string(b2.get_genre())<<endl;
        cout<<"copyright date: "<<b2.get_copyright_date()<<endl;
        cout<<"checked out: "<<b2.get_checked_out()<<endl;

        cout<<endl;
        cout<<"Using print operator <<:\n";
        cout<<"Default Book:\n"<<b<<endl;
        cout<<"New Book:\n"<<b2<<endl;

    } catch(Book::Invalid) {
        error("invalid book");
    }
    return 0;
}
