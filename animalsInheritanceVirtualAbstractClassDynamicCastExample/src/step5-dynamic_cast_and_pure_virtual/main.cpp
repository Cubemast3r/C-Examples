#include <iostream>
#include <vector>
#include "animal.h"

using namespace std;


void feedCat( Cat* cat )
{
    cout << "--> Cat \"" << cat->getName() << "\" gets yummy fish!" << endl;
} 

void feedDog( Dog* dog )
{
    cout << "--> Dog \"" << dog->getName() << "\" gets yummy liver!" << endl;
} 


int main()
{
    // WORK: Constructing an object of class Animal does not work anymore
    // cause it has a pure virtual method that *must* be overidden by derived classes.
    //// Animal abstractAnimal( "No_Identity" );
    //// abstractAnimal.saySomething();
    
    vector<Animal*> vecAnimals;
    vecAnimals.push_back(new Dog( "Bello" ));
    vecAnimals.push_back(new Cat( "Mia" ));

    for(std::vector<Animal*>::iterator it = vecAnimals.begin(); it != vecAnimals.end(); ++it) 
    {
        if( dynamic_cast<Dog*>(*it) ) feedDog(dynamic_cast<Dog*>(*it));
        else feedCat(dynamic_cast<Cat*>(*it));
        
        (*it)->saySomething();
    }

    for(std::vector<Animal*>::iterator it = vecAnimals.begin(); it != vecAnimals.end(); ++it) 
    {
        delete (*it);
    }
    
    return 0;
}
// g++ -g -Wall main.cpp -o animal.exe 
