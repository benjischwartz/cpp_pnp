#include <iostream>

using namespace std;

// Base class
class Animal {
    public:
        void animalSound() {
            cout << "The animal makes a sound \n";
        }
};

// Derived class
class Dog: public Animal {
    public:
        void animalSound() {
            cout << "The dog says woof \n";
        }
};

// Derived class
class Cat : public Animal {
    public:
        void animalSound() {
            cout << "The ccat says meow \n";
        }
};

int main() {
    Animal a;
    Dog d;
    Cat c;
    a.animalSound();
    d.animalSound();
    ((Animal)d).animalSound();
}
