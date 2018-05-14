#include <iostream>
#include "animal.h"

using namespace std;


int main()
{
    Animal abstractAnimal( "No_Identity" );
    abstractAnimal.saySomething();
  
    Animal* newDog = new Dog("Bello");
    Animal* newCat = new Cat("Mia");

    // WORK: Make Animal::saySomething virtual to see the difference !!!
    // WORK: Cat and Dog must be derive public from Animal in order to be able to access Animal::saySomething() from main !!
    newDog->saySomething();
    newCat->saySomething();
    
    // ATTENTION: dont forget to delete pointers otherwise you can get a memory leak !!!
    // WORK: Destructor of base class must be virtual too -> otherwise you get a warning !!
    delete newDog;
    delete newCat;

    return 0;
}
// g++ -g -Wall main.cpp -o animal.exe 
