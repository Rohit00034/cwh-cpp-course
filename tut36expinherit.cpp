/*Learnt theory about inheritance and its types refer 
video https://youtu.be/Dmrc82dL7E8?si=XVrMwBznQFfp7iae 
or pdf*/
//this is an experiment to find out if an obj of parent class can use the child class attributes 
#include <iostream>
using namespace std;
class Parent{
protected:
int a=22;
void getchilddata(){
// cout<<b; won't work as b is not defined meaninf we cannot access the child attributes
}
};
class Child : public Parent{ //inherited the parent class
public:
int b=88;
// cout<<a; we cannot use the cout here because a class is a template
void getparaentdata(){
    cout<<a;  //we can access the parent data;
}
};
int main(){
    Parent p1;
    // p1.b; it cannot access the child attributes even  if public
    Child c1;
    // cout<<c1.a; this can't be accessed directly as the a is protected it needs a function
    c1.getparaentdata(); //give us the parent data
    return  0;
}