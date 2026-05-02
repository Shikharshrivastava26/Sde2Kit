//diamond probelm in inheritance is problem with multiple and hierarchical inheritance where a class inherits from two classes 
//that both inherit from a common base class. This can lead to ambiguity when trying to access members of the base class through the derived class, 
//as it may not be clear which path to take to reach the base class members. This problem can be resolved using virtual inheritance, 
//which ensures that only one instance of the base class is created and shared among the derived classes, thus eliminating ambiguity.

#include <iostream>
using namespace std;

// Base class
class A{
    public:
    void show(){
        cout<<"Base class A\n";
    }
};

class B : virtual public A{
};

class C : virtual public A{
};

class D : public B, public C{
};

int main(){
    D d;

    //d.B::A::show(); // Ambiguous call to show() because D inherits from both B and C, which both inherit from A. or use virtual inheritance to resolve this issue
    d.show();

    return 0;
}