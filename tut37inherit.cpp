//LEARNT ABOUT INHERITANCE AND ITS SYNTAX WITH CONCEPTS
#include <iostream>
using namespace std;
class Employee{
    int salary;
    public:
    int id;
    Employee(int empid){
id=empid;
}
Employee(){
    cout<<"Default constructor employee called: ";
}
};
class Programmer : Employee{
public:
    int langaugecode=9;
Programmer(int empid){  /*as we have inherited from employee class whenever we will
    create an object of programmer class the default constructor of employee class will 
    be called first then parameterized constructor of the programmer class will be called*/
cout<<"\nParameterized constructor of Programmer class called\n";
    id = empid;
}
};
/*Syntax for inheriting class
class {{Derived class name}} : {{visibility mode}} {{Base class name}}{
//members/methods etc.
};*/
/*NOTE:THE DEFAULT VISIBILITY MODE IS PRIVATE
1)if teh visibility mode is private then PUBLIC MEMBERS of base class in the derived class 
are inherited as private 
2)if the visibility mode is public then PUBLIC MEMBERS of base class in the derived class 
are inherited as public 
3)PRIVATE MEMBERS OF A CLASS CAN NEVER BE INHERITED*/ 
int main(){
    Employee rohan(01);
    cout<<rohan.id<<endl;
    Programmer sudeep(02);
// cout<<sudeep.id; can't use id here as it was inherited as private
cout<<sudeep.langaugecode;
    return 0;
}