#include <string>
#include <iostream>

/**
 * @mainpage This is a small C++ example that shows the usage of inheritance, virtual methods and dynamic casts.
 * 
 * @author  Arno Wilhelm
 * @version 1.0
 * @since   2018-05-29 
 */


/**
 * @namespace std
 */
using namespace std;
/**
* 
* @class Animal is the abstract base class of all derived animal classes. 
* 
* @author  Arno Wilhelm
* @version 1.0
* @since   2018-05-29 
*/
class Animal
{
public: 
    /**
    * Constructor
    * 
    * @param name   Name of the animal.
    */
    Animal(const string& name) : name_(name) {;}

    /**
     * Getter returns the name of the animal.
     * 
     * @return string   Returns the name of the animal.
     */
    const string& getName() const { return name_; }
    /**
     * Virtual interface method must be implemented by derived classes. 
     * Depending on the type of animal they give print out an animal specific sound. 
     */
    virtual void saySomething() const = 0;

private:
    const string name_;
};

/**
* 
* @class Dog is derived from class Animal. 
* 
* @author  Arno Wilhelm
* @version 1.0
* @since   2018-05-29 
* @see Animal
*/
class Dog : protected Animal
{
public:
    Dog(const string& name) : Animal(name) {;}
    /**
     * Implements the saySomething method of base class Animal and prints out a dog specific sound.
     * 
     * @see Animal#saySomething
     */
    void saySomething() const { cout << "Wuff Wuuuff Wufff Wuuuuuuuuuufffff" << endl; }
};

/**
* 
* @class Cat is derived from class Animal. 
* 
* @author  Arno Wilhelm
* @version 1.0
* @since   2018-05-29 
* @see Animal
*/
class Cat : protected Animal
{
public:
    Cat(const string& name) : Animal(name) {;}
   /**
     * Implements the saySomething method of base class Animal and prints out a cat specific sound.
     * 
     * @see Animal#saySomething
     */
    void saySomething() const { cout << "Miiiiauuuooooooooouuu" << endl; }
};
