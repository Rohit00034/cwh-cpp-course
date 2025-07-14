//LEARNT ABOUT FRIEND FUNCTIONS AND IT'S PROPERTIES
#include <iostream>
using namespace std;
class Complex{
int a,b;
public:
void setnumber(int r,int i){
a=r;
b=i;
}
void dispnum(){
    cout<<"Your complex number is: "<<a<<"+"<<b<<"i\n";
}
friend Complex sumofboth(Complex o1,Complex o2); //declaring the sumofboth function as friend function using friend keyword
};
Complex sumofboth(Complex o1,Complex o2){ //this is a friend function which returns an object fo class complex
    Complex o3;
    // cout<<a; won't work because it needs objects to access the members it cannot do so directly
    o3.a=o1.a+o2.a;
    o3.b=o1.b+o2.b;  //we cannot access a and b without declaring the function as friend ,as the a and b are private
    return o3;
}
int main(){
 Complex c1,c2,c3;
c1.setnumber(2,3);
c1.dispnum();
c2.setnumber(1,4);
c2.dispnum();
c3=sumofboth(c1,c2);  //calling friend function
/* c3.sumofboth(c1,c2); this will not work because declaring a outer function as friend 
doesn't mean it has became a member function of a class which requires an object of that 
class to acces it.*/
c3.dispnum();
    return 0;
}

/* Properties of friend functions
1. Not in the scope of class
2. since it is not in the scope of the class, it cannot be called from the object of 
that class. c1.sumComplex() == Invalid
3. Can be invoked without the help of any object
4. Usually contans the objects as arguments
5. Can be declared inside public or private section of the class
6. It cannot access the members directly by thein names and need object_name.member_name 
to access any member.
*/