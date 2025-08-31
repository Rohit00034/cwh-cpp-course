//LEARNT ABOUT VIRTUAL FUNCTIONS
#include <iostream>
using namespace std;
class Base_class
{
public:
    int basevar = 1;
    virtual void display()
    {
        cout << "1 The value of base class var is " << basevar << endl;
    }
};
class Derived_class : public Base_class
{
public:
    int derivedvar = 2;
    void display()
    {
        cout << "2 The value of base class var is " << basevar << endl;
        cout << "2 The value of derived class var is " << derivedvar << endl;
    }
};
int main()
{
    Base_class *bptr;
    Base_class baseobj;
    Derived_class derivedobj;
    bptr = &derivedobj;
    // bptr->display() before making the display function of base class virtual this will run the function fo the base class
    bptr->display(); // here the derievd class function will be used even if the pointer is of base class
    /*runtime polymorphism is occuring here we can know that what will be the output of the
    code before compiling but here the compiler decides the binding at runtime */
    bptr->Base_class::display(); // using the scope resolution operator to acces the base class virtual fucntion
    return 0;
}