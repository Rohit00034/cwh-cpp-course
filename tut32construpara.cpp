//LEARNT ABOUT CONSTRUCTORS WITH DEFAULT ARGUMENTS
#include <iostream>
using namespace std;
class Simple{
int a,b;
public:
Simple(int x,int y=0){ //constructor with a default value
a=x;
b=y;
} 
void displaynum(){
cout<<"The number value of a and b is: "<<a<<","<<b<<endl;
}
};
int main(){
    Simple s1(2,3);
    s1.displaynum();
    Simple s2(2);
    s2.displaynum();
    return 0;
}