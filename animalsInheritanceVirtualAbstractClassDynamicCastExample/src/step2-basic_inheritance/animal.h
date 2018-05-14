#include <string>
#include <iostream>

using namespace std;

class Animal
{
public: 
    Animal(const string& name) : name_(name) {;}

    const string& getName() const { return name_; }
    void saySomething() const { cout << "What should I say? I am abstract!" << endl; }

private:
    const string name_;
};


class Dog : protected Animal
{
public:
    Dog(const string& name) : Animal(name) {;}
    // WORK: method overriding: comment out and make parent public to call base class 
    void saySomething() const { cout << "Wuff Wuuuff Wufff Wuuuuuuuuuufffff" << endl; }
    
};


class Cat : protected Animal
{
public:
    Cat(const string& name) : Animal(name) {;}
    // WORK: method overriding: comment out and make parent public to call base class 
    void saySomething() const { cout << "Miiiiauuuooooooooouuu" << endl; }
    
};
