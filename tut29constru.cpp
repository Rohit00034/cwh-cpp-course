//LEARNT ABOUT THE CONSTRUCTOR AND DEFAULT CONSTRUCTOR
#include <iostream>
using namespace std;
class Complex{
    int a,b;
    public:
    Complex();/*constructor declared this is a default constructor which does not have any
    parameters/arguments is defined by the class name and parenthesis , the constructor 
    is a specila type of function which is invoked/called whenever an onject is created*/
void displaynum(){
    cout<<"The complex number is : "<<a<<"+"<<b<<"i\n";
}
};
Complex ::Complex(){ //constructor defined
cout<<"Constructor called/invoked!!\n";
    a=10;
b=19;
}
int main(){
    Complex c1;  //here the constructor is called as object is created ,it does not have a ret type
    c1.displaynum();
    return 0;
}
/* Characteristics of Constructors
1. It should be declared in the public section of the class
2. They are automatically invoked whenever the object is created
3. They cannot return values and do not have return types
4. It can have default arguments
5. We cannot refer to their address
*/