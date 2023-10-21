#include "Link.h"


void print_all(Link* p);

int main() 
{
    God dummy_god = {"Some God", "Some mythology", "Chariot", "Lightning"};
    Link* norse_gods = new Link{"Thor", dummy_god};
    cout<<"Inserting Thor\n";
    print_all(norse_gods);
    norse_gods = norse_gods->add_ordered(new Link{"Odin", dummy_god});
    cout<<"Inserting Odin\n";
    print_all(norse_gods);
    norse_gods = norse_gods->add_ordered(new Link{"Zeus", dummy_god});
    cout<<"Inserting Zeus\n";
    print_all(norse_gods);
    norse_gods = norse_gods->add_ordered(new Link{"Freia", dummy_god});
    cout<<"Inserting Freia\n";
    print_all(norse_gods);
    cout<<endl<<endl;

    Link* greek_gods = new Link{"Hera", dummy_god};
    greek_gods = greek_gods->add_ordered(new Link{"Athena", dummy_god});
    greek_gods = greek_gods->add_ordered(new Link{"Mars", dummy_god});
    greek_gods = greek_gods->add_ordered(new Link{"Poseidon", dummy_god});

    // Fix a god
    Link* p = greek_gods->find("Mars");
    if (p) p->value = "Ares";

    // Move Zues into correct Pantheon
    Link* p2 = norse_gods->find("Zeus");
    if (p2) {
        // Fix list if Zeus is head
        if (p2 == norse_gods) norse_gods = p2->next();
        p2->erase();
        greek_gods = greek_gods->insert(p2);
    }

    // Print out lists
    print_all(norse_gods);
    print_all(greek_gods);
}

void print_all(Link* p) 
{
    cout<<"{";
    while(p) {
        cout<<p->value<<endl;
        cout<<'\t'<<"Name: "<<p->god.name<<endl;
        cout<<'\t'<<"Mythology: "<<p->god.mythology<<endl;
        cout<<'\t'<<"Vehicle: "<<p->god.vehicle<<endl;
        cout<<'\t'<<"Weapon: "<<p->god.weapon<<endl;
        if(p=p->next()) cout << ", ";
    }
    cout<<"}\n";
}
