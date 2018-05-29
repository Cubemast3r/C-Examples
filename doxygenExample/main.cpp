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


/*
 * @see https://de.wikibooks.org/wiki/C%2B%2B-Programmierung:_Dokumentation_mit_Doxygen
 * @see http://www-inf.int-evry.fr/cours/java/JAVADOC/writingdoccomments.html
 * @see https://www.tutorialspoint.com/java/java_documentation.htm
 * @see https://www.stack.nl/~dimitri/doxygen/manual/commands.html#cmdclass

$ doxygen -g doxygen.config


Configuration file `doxygen.config' created.

Now edit the configuration file and enter

  doxygen doxygen.config

to generate the documentation for your project

 * 
 * 
 * 
 * 
 * 
 * 
 * /
