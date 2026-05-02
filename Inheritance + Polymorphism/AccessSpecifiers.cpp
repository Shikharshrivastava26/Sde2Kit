//Protected inheritance preserves accessibility for further derived classes, while private inheritance restricts it only to the immediate derived class.a nd public always accessible.



#include <iostream>
using namespace std;

// 🔹 Base class
class Base {
public:
    int pub = 1;

protected:
    int prot = 2;

private:
    int priv = 3;
};

// 🔹 1. Public Inheritance
class PublicDerived : public Base {
public:
    void test() {
        cout << "PublicDerived:\n";
        cout << pub << endl;   // ✅ public
        cout << prot << endl;  // ✅ protected
        // cout << priv;       ❌ not accessible
    }
};

// 🔹 2. Protected Inheritance
class ProtectedDerived : protected Base {
public:
    void test() {
        cout << "ProtectedDerived:\n";
        cout << pub << endl;   // ✅ now protected
        cout << prot << endl;  // ✅ protected
         // cout << priv;       ❌ not accessible
    }
};

// 🔹 3. Private Inheritance
class PrivateDerived : private Base {
public:
    void test() {
        cout << "PrivateDerived:\n";
        cout << pub << endl;   // ✅ now private
        cout << prot << endl;  // ✅ private
        // cout << priv;       ❌ not accessible
    }
};

int main() {
    PublicDerived pd;
    pd.pub = 10;   // ✅ allowed (still public)
    pd.test();

    ProtectedDerived prd;
    // prd.pub = 20; ❌ not allowed (became protected)  as the ProtectedDerived is protected 
    prd.test();

    PrivateDerived pvd;
    // pvd.pub = 30; ❌ not allowed (became private) as the PrivateDerived is private 
    pvd.test();

    return 0;
}