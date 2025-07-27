//THE EXERCISE GIVEN IN TUT42 CAN BE DONE IN THIS WAY TOO 
/*
Create 2 classes:
1. SimpleCalculator Takes input of 2 numbers using a utility function and perfoms +,-,*, / 
and displays the results using another function.
2. ScientificCalculator Takes input of 2 numbers using a utility function and perfoms any 
four scientific operation of your chioice and displays the results using another function.
Create another class HybridCalculator and inherit it using these 2 classes:
Q1. What type of Inheritance are you using?
Q2. Which mode of Inheritance are you using?
Q3. Create an object of HybridCalculator and display results of simple and scientific 
calculator.
Q4. How is code reusability implemented?
*/
#include <iostream>
#include <cmath>
using namespace std;
class SimpleCalculator{
int a,b;
public:
void getdatasimple(){
  cout<<"Enter the value of a: "<<endl;
  cin>>a;  
  cout<<"Enter the value of b: "<<endl;  
  cin>>b;  
}
void performoperationsSimple(){
    cout<<"The adddtion of a and b is: "<<a+b<<endl;
    cout<<"The subtraction of a and b is: "<<a-b<<endl;
    cout<<"The multiplication of a and b is: "<<a*b<<endl;
    cout<<"a divide by b is:  "<<a/b<<endl;
}
};

class ScientificCalculator{
int a,b;
public:
void getdatascientific(){
  cout<<"Enter the value of a: "<<endl;
  cin>>a;  
  cout<<"Enter the value of b: "<<endl;  
  cin>>b;  
}
void performoperationsscientific(){
    cout<<"The value of sin(a) is:  "<<sin(a)<<endl; //sin(a) function from cmath lib of cpp
    cout<<"The value of cos(a) is:  "<<cos(a)<<endl; //cos(a) function from cmath lib of cpp
    cout<<"The value of tan(a) is:  "<<tan(a)<<endl; //tan(a) function from cmath lib of cpp
    cout<<"The value of exponential(a) is:  "<<exp(a)<<endl; //exp(a) function from cmath lib of cpp gives e^a

}
};
class HybridCalculator : public SimpleCalculator,public ScientificCalculator{

};
int main(){
HybridCalculator h1;
h1.getdatasimple(); 
h1.performoperationsSimple();     
h1.getdatascientific();      
h1.performoperationsscientific();     
    return 0;
}