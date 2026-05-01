/*
//Abstraction is the process of hiding the implementation details and showing only functionality to the user. It helps to reduce complexity and allows the programmer to focus on interactions at a higher level.


#include <iostream>
using namespace std;

// Abstract class
class Shape {
public:
    // Pure virtual function
    virtual void draw() = 0;  
};

// Derived class 1
class Circle : public Shape {
public:
    void draw() {
        cout << "Drawing Circle\n";
    }
};

// Derived class 2
class Rectangle : public Shape {
public:
    void draw() {
        cout << "Drawing Rectangle\n";
    }
};

int main() {
    Shape* s;   // pointer to abstract class

    Circle c;
    Rectangle r;

    s = &c;
    s->draw();   // Calls Circle's draw()  but we don't know how it is implemented

    s = &r;
    s->draw();   // Calls Rectangle's draw() but we don't know how it is implemented
}
*/

/*
//Inheritance allows one class (child/derived) to acquire properties and behavior of another class (parent/base).

#include <iostream>
using namespace std;

// Base class
class Animal {
public:
    void eat() {
        cout << "Animal eats\n";
    }
};

// Derived class
class Dog : public Animal {
public:
    void bark() {
        cout << "Dog barks\n";
    }
};

class Cat : public Animal {
public:
    void meow() {
        cout << "Cat meows\n";
    }
};

int main() {
    Dog d;
    d.eat();   // inherited
    d.bark();

    Cat c;
    c.eat();   // inherited
    c.meow();

    return 0;
}
    */


/*
//Encapsulation is binding data and methods together into a single unit (class) and restricting direct access using access specifiers (private, protected, public).

//its  a example of abstraction also as we are hiding the implementation details of the BankAccount class from the user and 
//providing a simple interface to interact with it.

#include <iostream>
using namespace std;

class BankAccount {
private:
    string name;
    double balance;

public:
    void setData(string n, double b) {
        name = n;
        balance = b;
    }

    void deposit(double amount) {
        if (amount > 0)
            balance += amount;
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance)
            balance -= amount;
    }

    void display() {
        cout << "Name: " << name << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main() {
    BankAccount acc;

    acc.setData("Shikhar", 1000);
    acc.deposit(500);
    acc.withdraw(200);

    // acc.balance = -10000; ❌ Not allowed

    acc.display();
}

*/


/*
//Polymorphism = “many forms” Same function name → behaves differently depending on context.


#include <iostream>
using namespace std;

class Shape {
public:
    virtual void draw() {
        cout << "Drawing Shape\n";
    }
};

class Circle : public Shape {
public:
    void draw() {
        cout << "Drawing Circle\n";
    }
};

class Rectangle : public Shape {
public:
    void draw() {
        cout << "Drawing Rectangle\n";
    }
};

int main() {
    Shape* s;

    Circle c;
    Rectangle r;

    s = &c;
    s->draw();   // Circle version

    s = &r;
    s->draw();   // Rectangle version
}

//compile time polymorphism = function overloading and operator overloading  --add(int a, int b) and 
//add(double a, double b) or add(int a, int b) and add(int a, int b, int c)  or operator + for adding two objects of a class

//run time polymorphism = virtual functions and function overriding  --virtual void draw() in base class and void draw() in derived class
//s->draw() will call the appropriate version of draw() based on the type of object s is pointing to at runtime (Circle or Rectangle) 
*/


// full code with all 4 pillars of OOP together


#include <iostream>
using namespace std;

// 🔶 ABSTRACTION (Abstract class)
class Shape {
public:
    // Pure virtual function
    virtual void draw() = 0;

    // Virtual destructor (good practice)
    virtual ~Shape() {}
};

// 🔶 INHERITANCE + ENCAPSULATION + POLYMORPHISM
class Rectangle : public Shape {
private:
    int length;   // 🔐 ENCAPSULATION (hidden data)
    int width;

public:
    // Setter (controlled access)
    void setDimensions(int l, int w) {
        if (l > 0 && w > 0) {
            length = l;
            width = w;
        }
    }

    // Getter
    int getArea() {
        return length * width;
    }

    // 🔁 POLYMORPHISM (override)  //override keyword is used just in case we use diff fxn like draw(int x) by mistake it will give us compile time error
    void draw() override {
        cout << "Drawing Rectangle\n";
    }
};

// 🔶 Another derived class
class Circle : public Shape {
private:
    int radius;   // 🔐 ENCAPSULATION

public:
    void setRadius(int r) {
        if (r > 0)
            radius = r;
    }

    int getArea() {
        return 3.14 * radius * radius;
    }

    void draw() override {
        cout << "Drawing Circle\n";
    }
};

int main() {
    Shape* s;   // base class pointer

    Rectangle r;
    r.setDimensions(4, 5);

    Circle c;
    c.setRadius(3);

    // 🔁 POLYMORPHISM in action
    s = &r;
    s->draw();  //if we not use virtual function for draw() in base class then it will call base class draw() which is not what we want

    s = &c;
    s->draw();

    // Access encapsulated data via methods
    cout << "Rectangle Area: " << r.getArea() << endl;
    cout << "Circle Area: " << c.getArea() << endl;

    return 0;
}
