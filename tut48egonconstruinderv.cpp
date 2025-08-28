/*SAW ACTUAL EXAMPLE OF CONSTRUCTOR IN DERIVED CLASS AND IT'S PRIORITIZATION AND IT'S 
CALLING SEQUENCE */
#include <iostream>
using namespace std;
/* Below is the order of the execution/call of constructor
case1:
class B :public A{
//constructor of A() first then B()
}
case2:
class A : public C ,public B{
//constructor of C() then B() then A()
}
case3:
class A :public B , virtual public C{     virtual classs cons is given priority first(if all are virtual class then the order of declation is followed)
//constructor of C() first then B() then A()
}
*/
class Base1{
int data1;
public:
Base1(int i){
    data1=i;
    cout<<"Base1 class constructor called\n";
}
void displaybase1(){
    cout<<"Value of data1 is : "<<data1<<endl;
}
};
class Base2{
int data2;
public:
Base2(int i){
    data2=i;
    cout<<"Base2 class constructor called\n";
}
void displaybase2(){
    cout<<"Value of data2 is : "<<data2<<endl;
}
};

class Derived:public Base1,public Base2{  //this order matters
int derived1,derived2;
public:   //case 4
Derived(int a,int b,int c, int d):Base2(b),Base1(a){ //this order doesn't matter still base1 constructor will be callled then base2
derived1=c;
derived2=d;
cout<<"Derived class constructor called\n";
}
void displayderived(){
    cout<<"value of derived1 is : "<<derived1<<endl;
    cout<<"value of derived2 is : "<<derived2<<endl;
}
};
int main(){
    Derived d1(1,2,3,4);
    d1.displaybase1();
    d1.displaybase2();
    d1.displayderived();
    return 0;
}