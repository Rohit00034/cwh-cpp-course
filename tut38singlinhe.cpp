//LEARNT ABOUT SINGLE INHERITANCE AND A REMINDER THAT WE CAN ACCESS THE PRIVATE DATA INDIRECTLY USING FUNCTIONS
#include <iostream>
using namespace std;
class Base{
    int data1; //private member can only be accessed through getdata1 fnction
    public:
    int data2;
    void setdata();
    int getdata1();
    int getdata2();
};
void Base :: setdata(){
    data1=10;
    data2=20;
}
int Base :: getdata1(){
    return data1;
}
int Base :: getdata2(){
    return data2;
}
class Derived : public Base{
int data3;
public:
void process(){
    data3=data2*getdata1(); /*we cannnot acces the data1 directly as the data1 is private 
    so we use the getdata1 function as it returns the value of data1*/

}
void display(){
    cout<<"The value of the data 1 is: "<<getdata1()<<endl;
    cout<<"The value of the data 1 is: "<<data2<<endl;//we can access the data2 as it is inherited as a public member
    cout<<"The value of the data 1 is: "<<data3<<endl;
}
};
int main(){
Derived d1;
d1.setdata();
d1.process();
d1.display();    
    return 0;
}
//WHAT IF WE INHERIT THE CLASS AS protected? CHECK IT IN THE NEXT CPP CODE