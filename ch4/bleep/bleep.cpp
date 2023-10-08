#include "std_lib_facilities.h"

int main()
{
    vector<string> words;
    vector<string> bleep_words = {"these", "words", "are", "forbidden", "so", "don't", "use", "them"};
    cout<<"Please enter your sentence:\n";

    for (string word; cin >> word;) {
        words.push_back(word);
    }

    for(string word: words) {
        bool bleeped = false;
        for(string bleep: bleep_words) {
            if (word == bleep) {
                cout<<"BLEEP\n";
                bleeped = true;
                break;
            }
        }
        if (!bleeped) {
            cout << word << '\n';
        }
    }

}
