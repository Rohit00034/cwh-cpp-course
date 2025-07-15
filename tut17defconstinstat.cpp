/*We learnt about how to make a function inline function and static variables and default
arguments and constant arguments in functions*/
#include <iostream>
using namespace std;
//iNLINE FUNCTION IS A REQUEST TO THE COMPILER IT MAY OR MAY NOT ACCEPT IT DUE TO COMPILER LEVEL OPTIMIZATION
inline int division(int a,int b){ /*the inline keyword makes the function come literally 
    in line ,it's like macro function of NASM(assembly langauge) it expands the code 
    of the function at compile time instead of calling it saving time and resources,
    does so by avoiding call overhead*/
//NOTE:NOT RECOMMENDED TO USE LOOPS AND SWITCH CASE STATEMENTS AND STATIC VARIABLES WITH INLINE FUNC  
return a/b;
}
//static variable
//assume you want to print numbers from 1 to 10 
int printnum(){
    static int c=0; //static varible  //this line will be executed only once THAT IS THE VARIBLE WILL BE INITIALIZED ONLY ONCE
    c=c+1;   //the value of c is retained/kept as it is a static variable
    return c;
}
//DEFAULT ARGUMENTS
//NOTE:ALWAYS DECLARE DEFAULT ARGUMENTS AT LAST JUST LIKE BELOW IF NOT IT WILL GIVE AN ERROR
float moneyback(float currentmoney,float interestrate=1.04/*default argument 1.04=100%+4%*/){
    return currentmoney*interestrate;
}
//CONST ARGUMENTS
float moneyback2(float currentmoney,const float interestrate=1.04){/*due to const keyword 
    the interest rate cannot be changed or a value as a parameter cannot be passed*/
    return currentmoney*interestrate;
}
int main(){
    int a=8,b=2;
    cout<<"\n"<<division(a,b);   //the code of inline function will be pasted at here at call
    //caling printnum() function 10 times
    cout<<"\n"<<printnum()<<endl;
    // cout<<printnum()<<endl;
    // cout<<printnum()<<endl;
    // cout<<printnum()<<endl;
    // cout<<printnum()<<endl;
    // cout<<printnum()<<endl;
    // cout<<printnum()<<endl;
    // cout<<printnum()<<endl;
    // cout<<printnum()<<endl;
    // cout<<printnum()<<endl;
    int money=100000;
    cout<<"Current money amount is :"<<money<<"\nMoney after 1 year at interest rate of 4% will be "<<moneyback(money);
    cout<<"\nCurrent money amount is :"<<money<<"\nFor VIP: Money after 1 year at interest rate of 10% will be "<<moneyback(money,1.1);
    //10% FOR VIP HERE WE ARE OVERWRITING THE DEFAULT ARGUMENT 
    
    return 0;
}