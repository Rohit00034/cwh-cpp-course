//LEARNT ABOUT CONSTRUCTOR OVERLOADING
//wwe can define multiple constructors  in a single class defering by parameters passed
#include <iostream>
using namespace std;
class Complex{
int a,b;
public:
Complex(){  //this will be used if nothing is passed
    a=0;
    b=0;
}
Complex(int x){ //this will be used if one value is passed
    a=x;
    b=0;
}
Complex(int x,int y){ //this will be used if two values are passed
    a=x;
    b=y;
}         
void display(){
    cout<<"Your number is: "<<a<<"+"<<b<<"i\n";
}
};
int main(){
    Complex c1;
    c1.display();
    Complex c2(2);
    c2.display();
    Complex c3(2,5);
    c3.display();
    return 0;
}