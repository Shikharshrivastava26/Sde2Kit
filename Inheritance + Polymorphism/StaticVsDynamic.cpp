//Binding = deciding which function to call.

/*
//Static binding = compile time binding = early binding  -- function overloading and operator overloading no virtual calls 

#include <iostream>
using namespace std;

class Animal {
public:
    void speak() {
        cout << "Animal speaks\n";
    }
};

int main() {
    Animal a;
    a.speak();  // ✅ decided at compile time
}
*/

//Dynamic binding = runtime binding = late binding  -- virtual functions

#include <iostream>
using namespace std;

class Animal {
public:
    virtual void speak() {
        cout << "Animal speaks\n";
    }
};

class Dog : public Animal {
public:
    void speak() override {
        cout << "Dog barks\n";
    }
};

int main() {
    Animal* a;
    Dog d;

    a = &d;
    a->speak();  // 🔥 runtime decision → Dog's version
}