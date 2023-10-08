#include "std_lib_facilities.h"

int main()
{
    string first_name {"???"};
    string friend_name {"???"};
    char friend_sex {0};
    string pronoun {"them"};
    int age {0};
    string age_message {""};
    cout << "Enter the name of the person you want to write to:\n";
    cin >> first_name;
    cout << "Enter the age of the recipient:\n";
    cin >> age;
    if (age <= 0 or age >= 110) {simple_error("you're kidding!");}
    if (age < 12) {
        age_message = "Next year you will be " + to_string(age+1) + ".\n";
    } if (age == 17) {
        age_message = "Next year you will be able to vote.\n";
    } if (age > 70) {
        age_message = "I hope you are enjoying retirement.\n";
    }
    cout << "Enter the name of a friend:\n";
    cin >> friend_name;
    cout << "Enter an 'm' if the friend is male or an 'f' if the friend is female:\n";
    cin >> friend_sex;
    if (friend_sex == 'm') {
        pronoun = "him";
    } else if (friend_sex == 'f') {
        pronoun = "her";
    }
    cout << "Dear " << first_name << ",\n";
    cout << "\n\tHow are you? I am fine. I miss you.\n";
    cout << "I wanted to ask how everything is going with your studies. Your mother and I are thinking of you.\n";
    cout << "Have you seen " << friend_name << " lately? "; 
    cout << "If you see " << friend_name << " please ask " << pronoun << " to call me.\n";
    cout << "I hear you just had a birthday and you are " << age << " years old.\n";
    cout << age_message;
    cout << "Yours sincerley,\n\nBenji\n";
    return 0;
}
