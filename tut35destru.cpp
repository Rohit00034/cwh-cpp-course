//LEARNT ABOUT THE DESTRUCTOR
/*The destructor is just like a function and its work is to deallocate the memory or we 
can say cleanup the memory allocated to the objects by constructor or any other source 
it is called when the scope of the object ends*/
//destructor never take and argumnet nor returns a value
#include <iostream>
using namespace std;
int count=0;  //global variable
class Num{
public:
int a;    
Num(){
    ::count++;  //we can use ::count also to access the glbl var
    cout<<"Constructor called for object number: "<<count<<endl;
    a=11;
}
~Num(){   //this is the destructor which is defined by ~ClassName
cout<<"Destructor called for object number: "<<count<<endl;
count--;
}
};
int main(){
    cout<<"we are in teh main block of the code"<<endl;
    cout<<"Creating first object "<<endl;
    Num n1;
    {    //this is called a block ,the scope of anything in block is till the block ends that  is inside the block only 
        cout<<"Entering the block\n";
cout<<"Creating 2 more objects"<<endl;
Num n2,n3;
cout<<"Exiting the block\n";

    }
    n1.~Num(); //this manual call to the destructor won't act as a destructor but as a function
    /*When the destructor is automatically called by the compiler then only the object 
    memmory is deallocated*/
// cout<<n1.a; //we can still access the memory data of n1 which shows that the n1 object is noy destroyed
    cout<<"Back to main\n";
    return 0;
}