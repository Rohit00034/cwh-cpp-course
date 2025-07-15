/*Learnt about how we can individually make member functions of one class as a friend 
function to let it access the private members other, and alos instead of making each 
function a friend make the whole class friend to let all the other classe's function 
access private members/data*/
//Make member function of another class as a friend function and add real part of complex number
#include <iostream>
using namespace std;
class Complex;  /*as the compiler compiles from top to down ,we have gave compiler a forward 
declaration because if we do not we cannot make a function in calculator class with 
parameters as objects of complex class because compiler does not know that such class 
exists and throws and error*/ 
class Calculator{
public: 
int addrealcomplex(Complex o1,Complex o2); //forward declaration or we can say declaration 
int addimagcomplex(Complex o1,Complex o2); 
/* {return (o1.a+o2.a)}; NOW this function definition won't work because the compiler 
won't know that the complex class has "a" as a member so we shouldn't define the 
function before definition of Complex class*/
int add(int a,int b){
    return(a+b);
}

};
class Complex{
int a, b;
public:
void getcomplxnum(int r,int i){
    a=r;
    b=i;
}
void displaynum(){
    cout<<"Your complex number is: "<<a<<"+"<<b<<"i\n";
}
//individually declarinig the functions as friend 
/*but what if there are 100 such functions ?
in that case we won't friend each of 100 functions what we will do is declare the class
as friend class*/
/*friend int Calculator::addrealcomplex(Complex o1,Complex o2);/*Declaring the addrealcomplex 
function of calculator as a friend of Complex class*/
// friend int Calculator::addimagcomplex(Complex o1,Complex o2);
/*Declaring the whole class as friend so each function of calculator has permission 
to access all the private members of Complex class*/ 
friend class Calculator;
};

/*writing a function of class calculator to add the real part of the complex nums of 2 
objects of class Complex but how will the calculator class access the private membrs
of Complex class . Answer is by friend function*/
int Calculator::addrealcomplex(Complex o1,Complex o2){ /*defining the addrealcomplex function 
    after it is declared a friend inside the Complex class*/
    return (o1.a+o2.a);
}
int Calculator::addimagcomplex(Complex o1,Complex o2){ /*defining the addrealcomplex function 
    after it is declared a friend inside the Complex class*/
    return (o1.b+o2.b);
}
int main(){
    Complex c1,c2;
    c1.getcomplxnum(2,3);
    c2.getcomplxnum(3,6);
    Calculator calc;
    cout<<"The addition of the real part of 2 complex numbers is: "<<calc.addrealcomplex(c1,c2)<<" and imag part is:"<<calc.addimagcomplex(c1,c2);
    return 0;
}