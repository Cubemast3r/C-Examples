#include <iostream>
#include "animal.h"

using namespace std;


int main()
{
    Animal abstractAnimal( "No_Identity" );
    abstractAnimal.saySomething();
    
    return 0;
}
// g++ -g -Wall main.cpp -o animal.exe 
