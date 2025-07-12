/*LEARNT FUNCTION OVERLOADING(SAME NAME DIFF TASK/PARAMETERS OR DIFF NUM OF PARAMETERS
OR RETURN TYPE )*/ 
#include <iostream>
#include <cmath>
using namespace std;
//sum of 2 numbers(2 parameters)
int sum(int a ,int b){
    return a+b;
}
//sum of 3 numbers(3 parameters)
int sum(int a ,int b,int c){
    return a+b+c;
}
//volume of cylinder(pie r^2 h)
float volume(float rad,int height){
return M_PI*rad*rad*height;
}
//volume of cube
float volume(float side){
    return side*side*side;
}
int main(){
    cout<<"Sum of 2 and 1 is "<<sum(2,1)<<endl;
    cout<<"Sum of 2 ,3 and 1 is "<<sum(2,3,1)<<endl;
    cout<<"Volume of cube of side 2.3 is "<<volume(2.3)<<endl;
    cout<<"Volume of a cylinder of radius 2 and height 3 is "<<volume(2,3)<<endl; 
    return 0;
}