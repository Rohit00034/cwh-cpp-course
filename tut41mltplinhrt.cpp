//LEARNT ABOUT MULTIPLE INHERITANCE
/*syntax for inheriting multiple classes
class {{derived class name}} : {{visibiltiy mode}} class1 ,{{visibiltiy mode}} class2
*/ 

#include <iostream>
using namespace std;
class Base1{
protected:
int intbase1;
public:
void setintbase1(int b1){
intbase1=b1;
}
};
class Base2{
protected:
int intbase2;
public:
void setintbase2(int b2){
intbase2=b2;
}
};
class Derived : public Base1,public Base2{
public:
void show(){
    cout<<"The value of intbase1 is: "<<intbase1<<endl;
    cout<<"The value of intbase2 is: "<<intbase2<<endl;
    cout<<"The addition of both is   : "<<intbase2+intbase1<<endl;
}
};
/*THE MEMBERS AND FUNCTIONS IN INHERITED DERIVED CLASS WILL LOOK LIKE THIS
DATA MEMBERS:-
intbase1-->protected
intbase2-->protected
MEMBER FUNCTIONS:-
setintbase1()-->public
setintbase2()-->public
show()-->public
*/
int main(){
    Derived obj1;
    obj1.setintbase1(20);
    obj1.setintbase2(40);
    obj1.show();
    return 0;
}