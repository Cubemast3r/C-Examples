#include <string>
#include <iostream>

using namespace std;

class Animal
{
public: 
    Animal(const string name) : name_(name) {;}

    const string& getName() const { return name_; }
    void saySomething() const { cout << "What should I say? I am abstract!" << endl; }

private:
    const string name_;
};
