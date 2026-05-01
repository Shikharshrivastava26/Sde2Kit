#include <iostream>
using namespace std;

struct example1{
    string name; //public by default
    int age;  //public by default

    void Display(){
        cout<<"Struct : My name is " << name << " and my age is " <<age; 
    }
};

class example2{
    string name; //private by default
    int age;  //private by default

    public:
    //need constructor 
    example2(string n ,int a){
        name = n;
        age = a;
    }

    void Display(){
        cout<<" Class : My name is " << name << " and my age is " <<age; 
    }
};


int main(){
    //struct call
    example1 e1;
    e1.name = "Shikhar";
    e1.age = 25;
    e1.Display();

    //class call
    example2 e2("Shikhar",25);
    e2.Display();


    return 0;
}
