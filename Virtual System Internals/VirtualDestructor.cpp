#include <iostream>
using namespace std;

class Base {
public:
    Base(){
        cout << "Base constructor\n";
    }
    virtual ~Base() {
        cout << "Base destructor\n";
    }
};

class Derived : public Base {
    int* data;
public:
    Derived() {
        data = new int[5];
        cout << "Derived constructor (allocated memory)\n";
    }

    ~Derived() {
        delete[] data;
        cout << "Derived destructor (freed memory)\n";
    }
};

int main() {
    Base* b = new Derived();
    delete b;   // ✅ correct
}