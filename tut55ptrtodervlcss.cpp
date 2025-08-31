//LEARNT ABOUT POINTER TO DERIVED CLASSES AND DEMONSTRATED RUNTIME POLYMORPHISM
#include <iostream>
using namespace std;
class Base_class{
public:
int basevar;
void display(){
    cout<<"The value of base class var is "<<basevar<<endl;
}
};
class Derived_class:public Base_class{
public:
int derivedvar;
void display(){
    cout<<"The value of base class var is "<<basevar<<endl;
    cout<<"The value of derived class var is "<<derivedvar<<endl;
}
};
int main(){
    Base_class* base_class_pointer; //base calss pointer
    Derived_class derivedobj;//object of drived class
    base_class_pointer=&derivedobj;//base class pointer pointing to the derived class object
    /*now here we can only use the attribute fo the base class using the base class pointer
    even though the pointer is pointing the derived class object*/
    base_class_pointer->basevar=43;//we can acces the base class varr
    base_class_pointer->display();/*will run the base class function as the pointer is of 
    base class ,late binding occurs here*/
    // base_class_pointer->derivedvar=98;//will throw a error
    Derived_class * derived_class_pointer;
    derived_class_pointer=&derivedobj;
    derived_class_pointer->basevar=90; //we can acces the attrivbutes of the base class too
    derived_class_pointer->derivedvar=178;
    derived_class_pointer->display(); //here the derived class funciton will run
    derived_class_pointer->Base_class::display(); //we can also acces hte base class fucntion using the scope resoultion operator
    //THIS ABOVE DECIDING OF WHICH FUNCTION WILL BE USED IS DONE IN RUNTIME 
    return 0;
}