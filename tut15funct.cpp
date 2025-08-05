//LEARNT ABOUT FUNCTIONS AND FUNCTION PROTOTYPING/forward referencing(DECLARING FUNCTION BEFORE MAIN AND DEFINING THEM AFTER) 
#include <iostream>
using namespace std;
//int sum(int a,int b); correct
int sum(int ,int ); //we can also do it like this
void extract(void);    //we need to meantion void in the ()
int main(){
int a=15,b=10;
//a and b here are actual parameters
//cout<<sum(a,b); 
/*gives error 'sum' was not declared in this scope beacuse sum is declared after main because we have to declare
any function before main() function. WE WILL GET THIS ERROR UNTIL WE USE FUNCTION PROTOTYPING*/     
    return 0;
}
int/*return type*/ sum(int a,int b){    //can't do sum(int a,b)
int c=a+b;
//a and b are formal parameters here
return c;
}
void extract(){  //void can be used to return nothing
    cout<<"extracting....";
}