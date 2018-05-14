#include <iostream>
#include "animal.h"

using namespace std;


int main()
{
    Animal abstractAnimal( "No_Identity" );
    abstractAnimal.saySomething();
    
    Dog bello( "Bello" );
    bello.saySomething();
    
    Cat mia( "Mia" );
    mia.saySomething();
    
    return 0;
}
// g++ -g -Wall main.cpp -o animal.exe 
