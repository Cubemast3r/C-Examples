#include <iostream>
#include <vector>
#include "animal.h"

using namespace std;


int main()
{
    // WORK: Costruction of base class must be removed when there are pure virtual methods ! 
    Animal abstractAnimal( "No_Identity" );
    abstractAnimal.saySomething();
    
    vector<Animal*> vecAnimals;
    
    vecAnimals.push_back(new Dog( "Bello" ));
    vecAnimals.push_back(new Cat( "Mia" ));

    for(std::vector<Animal*>::iterator it = vecAnimals.begin(); it != vecAnimals.end(); ++it) 
    {
        Animal* now = *it;
        now->saySomething();
        // WORK: you have to use paranthesis: operator presedence ?
        (*it)->saySomething();
    }

    for(std::vector<Animal*>::iterator it = vecAnimals.begin(); it != vecAnimals.end(); ++it) 
    {
        delete (*it);
    }
    
    return 0;
}
// g++ -g -Wall main.cpp -o animal.exe 
