#include <string>
#include <iostream>

using namespace std;

class Animal
{
public: 
    Animal(const string& name) : name_(name) { cout << "* Animal \"" << getName() << "\" constructed" << endl;}
    virtual ~Animal() { cout << "+  Animal \"" << getName() << "\" destroyed" << endl; }

    const string& getName() const { return name_; }
    // WORK: Pure virtual method: now Animal cannot be declared direclty and *must* be derived !!
    virtual void saySomething() const = 0;

private:
    const string name_;
};


// WORK: change public keyword to protected and see what happens !!
class Dog : public Animal
{
public:
    Dog(const string& name) : Animal(name) { cout << "* Dog \"" << getName() << "\" constructed" << endl;}
    ~Dog() { cout << "+  Dog \"" << getName() << "\" destroyed" << endl; }
    // WORK: method overriding: comment out and make parent public to call base class 
    void saySomething() const { cout << "Wuff Wuuuff Wufff Wuuuuuuuuuufffff" << endl; }
};


class Cat : public Animal
{
public:
    Cat(const string& name) : Animal(name) { cout << "* Cat \"" << getName() << "\" constructed" << endl;}
    ~Cat() { cout << "+ Cat \"" << getName() << "\" destroyed" << endl; }
    // WORK: method overriding: comment out and make parent public to call base class 
    void saySomething() const { cout << "Miiiiauuuooooooooouuu" << endl; }
};
