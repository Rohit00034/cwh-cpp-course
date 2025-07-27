//LEARNT ABOUT INITIALIZATION LIST IN A PARAMETERIZED CONSTRUCTOR TO INITIALIZE VALUES OF DATA MEMBERS
/*initialization list is basically a way to initialize or assign values to the dtat members
of class in a parameterizedconstructor ,this is used when the constructor body is too 
complex to assign this values in it(that is to assign the values here itself to avoid 
increasing complexity)

Syntax for Initialization list in a constructor
constructor (Argument list ):initialization-section{
assignment+other code
}
class Test {
int a;
int b;
Test(int i,int j) : a(i),b(j){
constructor body
}
};
*/
#include <iostream>
using namespace std;
class Test{
    int a;  
    int b;
  public:
//   Test(int i,int j):a(i),b(j){ //this line means a=i and b=j;
//   Test(int i,int j):a(i),b(j+2){ this will add 2 in j and assign to b 
//   Test(int i,int j):a(i),b(2*j){this will multiply j by 2 and assign it to b 
//   Test(int i,int j):a(i),b(a*j){this will multtiply a with j and assgin it to b 
/*   Test(int i,int j):b(j),a(i+b){   /*avoid doing this as we may get garbage value for a as 
    it is initialized first in the private block of the class so it may get a garbage value
    */
   Test(int i,int j):a(i){ //we can also use it like this
    b=j;
cout<<"Constructor called!\n";
cout<<"The value of a is: "<<a<<endl;
cout<<"The value of b is: "<<b<<endl;
  }  
};
int main(){
  Test t(2,3);
  
    return 0;
}