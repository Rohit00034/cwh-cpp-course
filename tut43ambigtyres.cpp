//LEARNT ABOUT AMBIGUITY RESOLUTION IN INHERITANCE
#include <iostream>
using namespace std;
class Base1{
public:
void greet(){
    cout<<"How are you?"<<endl;
}
};
class Base2{
public:
void greet(){
    cout<<"Aap kaise ho?"<<endl;
}
};
class Derived : public Base1 ,public Base2{

};
class D : public Base1{
public:
void greet(){  //this will override the Base1 class function
    cout<<"Hello noob people"<<endl;
}
};
int main(){
    cout<<"\nAMBGUITY 1"<<endl;
//Ambiguity 1
    Base1 b1obj;
b1obj.greet();    
Base2 b2obj;
b2obj.greet();
Derived d1obj;
/*d1obj.greet(); this will give us error that greet()is ambigous meaning it doesn't get which greet()to use
as there are 2 greet( ) functions this can be resolved using the scope resolution operator*/
d1obj.Base1::greet(); //shows we are using the greet function of Base1 class
//Ambuiguity 2
cout<<"\nAMBGUITY 2"<<endl;
D dobj;  /*the greet()function of the D class will automatically override the greet function from the Base1 
class whenever it is present if not then the Base1 class function will run*/
dobj.greet();
    return 0;
}