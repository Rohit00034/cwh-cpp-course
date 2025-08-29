//LEARTN ABOUT THIS POINTER
#include <iostream>
using namespace std;
class A{
int a;
    public:
    void setdata(int a){
    /* a=a; //here we tried to assign the local varaible to the class variable
    but instead what will happen is the fucntion prioritizes the local variable means it sees
    'a' as a local variable everywhere , so if we want to assign the local value to the 
    object then we need to use the this pointer*/
    this->a=a;
    //this keyword is a special pointer which points to the object which invokes the function  
    }
    void getdata(){
        cout<<"The value of a is "<<a<<endl;
    }
    //we can also return an object using this pointer
    A & retobj(){ /*here A& acts as a reference variable , it means "an object of class A "
        "A &a=returned object" we can alos let it be A alone as a has became a data type
        (its a class)*/
        return *this;  /*here we are dereferencing the this pointer as the this pointer 
        points to the address of the object*/
    } 
};
int main(){
    //old method
    // A obj1;
    // obj1.setdata(2);
    // obj1.getdata();
    //new method
    A *ptr=new A;
    ptr->setdata(2);
    ptr->getdata();
    return 0;
}