//LEARNT ABOUT FUCNTION TEMPLATE JUST LIKE CLASS TEMPLATE
#include <iostream>
using namespace std;
// int average(int a,int b){
//     int avg=(a+b)/2;
//     return avg;
// }
// float averagef(float a,float b){
//     float avg=(a+b)/2;
//     return avg;
// }
// instead of defining or overloading functiopn for diff data types we will use template
template <class T1,class T2>
float average(T1 a,T2 b){
    float avg=(a+b)/2;
    return avg;
}
int main(){
    cout<<"Average of two int is "<<average(2,3)<<endl; 
    cout<<"Average of two float is "<<average(2.4,3.7)<<endl; 
    cout<<"Average of one float and one  int  is "<<average(2.4,3)<<endl; 
    return 0;
}