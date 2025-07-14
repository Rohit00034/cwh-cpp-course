//LEARNT PASSING OBJECTS AS FUNCTION PARMETERS
#include <iostream>
using namespace std;
class Complex{
int a,b;
public:
void setnum(int p1,int p2){
a=p1;
b=p2;
}
void setnumbyaddobjdat(Complex o1,Complex o2){ //defining objects as arguments
a=o1.a+o2.a;
b=o1.b+o2.b;
}
void dispcmplx(){
    cout<<"Your complex number is: "<<a<<"+"<<b<<"i"<<endl;
}
};
int main(){
    Complex c1,c2,c3;
    c1.setnum(2,3);
    c1.dispcmplx();
    c2.setnum(1,7);
    c2.dispcmplx();
    c3.setnumbyaddobjdat(c1,c2);//passed objects as function parameters
    c3.dispcmplx();
    return 0;
}