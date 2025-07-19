//LEARNT ABOUT COPY CONSTRUCTOR 
#include <iostream>
using namespace std;
class Number{
int a;
public:
Number(){a=0;} //default constructor
Number(int num){ //parametreized constructor
    a=num;
}
Number(Number &obj){ //this id copy constructor in which a object is passed to make its copy
    cout<<"Copy Constructor called!!\n";
    a=obj.a;
    
} //even if the copy constructor isn't defined Number n4(n2); WILL STILL WORK!! beacause every class has it's own copy constructor defined by default
void show(){
    cout<<"The number for this object is "<<a<<endl;
}
};
int main(){
    Number n1,n3; //default constructor will be called
    n3.show();
    Number n2=Number(2); //parameterized constructor will be called
    n2.show();
    //but what if you want an object to be the same copy of another object,then we use copy constructor
    Number n4(n2);  //using copy constructor HERE n4 will resemble n2
    n4.show();
    n3=n1;  //will the copy constructor be called? No it won't because we are just assigning the object a value(equating to another object)
n3.show();
Number n5 =n4; //will the copy constructor be called? Yes it will because we are actually creating an object of class
  n5.show();  
  return 0;
}