#include "std_lib_facilities.h"

// Program that checks if a sentence according to the 6.4.1 grammar.
// Assume every language is terminated by a full stop surrounded by whitespace.
// E.g. "birds fly but the fish swim . " is a sentence.
// For each sentence, program should response "OK" or "not OK."
// Read into a string using >> (no tokens).
//

// GRAMMAR
//
// Sentence:
//      Noun Verb
//      Sentence Conjunction Sentence
// Conjunction:
//      "and"
//      "or"
//      "but"
// Noun:
//      "birds"
//      "fish"
//      "C++"
// Verb:
//      "rules"
//      "fly"
//      "swim"

bool sentence();
bool conjunction();
bool noun();
bool verb();

int main()
{
    cout<<"Please enter your sentence:\n";
    bool res = sentence();

    while (true) {

        char check_end;
        cin>>check_end;
        if (check_end == '.') {
            cout<<"OK.\n";
            return 0;
        }

        else {cin.putback(check_end);}

        bool conjunction_res = conjunction();
        if (!conjunction_res) {
            cout<<"not OK.\n";
            return 0;
        }
        bool sentence_res = sentence();
        if (!sentence_res) {
            cout<<"not OK.\n";
            return 0;
        }
    }
    return 0;
}

bool sentence()
{
    cout<<"in sentence()\n";
    bool noun_res = noun();
    bool verb_res = verb();
    if (!noun_res or !verb_res) {return false;}    
    return true;
}

bool conjunction()
{
    cout<<"in conjunction()\n";
    string input;
    cin >> input;
    if (input == "and" or input == "or" or input == "but") {
        cout<<"returning true.\n";
        return true;
    }
    return false;
}

bool noun()
{
    cout<<"in noun()\n";
    string input;
    cin >> input;
    if (input == "birds" or input == "fish" or input == "C++") {
        cout<<"returning true.\n";
        return true;
    }
    return false;
}

bool verb()
{
    cout<<"in verb()\n";
    string input;
    cin >> input;
    if (input == "rules" or input == "fly" or input == "swim") {
        cout<<"returning true.\n";
        return true;
    }
    return false;
}
