/*Learnt that a function ends after it encounters a return statement if it has a 
return type,learnt about recursive function and how to calculate a factorialand fibonacci sequence*/ 
#include <iostream>
using namespace std;
//recursive function
//REMEMBER: SOMETIMES RECURSION GIVES A HUGE CALL OVERHEAD
int fact(int num){
static int factorial=num;  //here we used the static to retain the value of factorial
/*if we have a static variable in a recursive function then does the static variable get's 
declared again and again in cpp?
No, a static variable inside a recursive function does not get declared again and again in C++*/
factorial=factorial*(--num);
// return factorial;  if we do this ,then it will just stop the function there itself
if(num!=1){   //meaning this will not be executed
    fact(num);
    }
return factorial;
}
//another way of writing the factorial function
int factorial(int n){
    if(n<=1){
        return 1;
    }
    return n*factorial(n-1);  //n!=n*(n-1)!
}
int check1(){
return 12;        //because we returned the value to the function here
cout<<"hellfire";  //this isn't getting executed
}
//fibonacci sequence

int fib(int a){
    if(a<2){     //this ensures that the first two values at index  0 and 1 are 1
        return 1;
    }
    return fib(a-2)+fib(a-1);
}
/*BREAKDOWN OF fib(5)
fib(3)+fib(4)
fib(1)+fib(2)+fib(2)+fib(3)  here we can see there is 2 calls of fib(2) which show increase in call overhead*/
void runfib(int seq){
    static int count=0;
    if(count<=seq){           //this function gives first n(seq in this case) fibonacci sequence
        cout<<" "<<fib(count)<<" ";
        count++;
        runfib(seq-1);
    }
}
//WRONG
// int fibsequence(int n){
// static int count=0;
// if(count==n){
//     return 1;
// }
//     static int strt=0;
// static int next=1;
// static int prev=strt;
// next=next+prev;
// prev=prev+(next-prev);
// count++;
// fibsequence(n-1);
// return prev;

// }


int main(){
    int a=6;
    cout<<"Factorial of "<<a<<" is "<<fact(a)<<endl;
    cout<<"Factorial of "<<a<<" is "<<factorial(a)<<endl;
    // cout<<check1(); gives 12
    cout<<"Fibonacci sequence\n";
    runfib(18);  //Do not pass a big value in this function
    return 0;
}
