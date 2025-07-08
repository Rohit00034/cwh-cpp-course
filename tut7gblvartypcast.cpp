#include <iostream>
using namespace std;
int c=45; //global variable
int main(){
    cout<<::c;
    34.4 ;//this is double by deafult but if we want it to be float it can be done so below by adding f at the end
    34.4f;   //F/f
    34.4l; //this is long double L/l
    //REFERENCE Variable
    float x=40;
    float & y=x;
    cout<<endl<<y<<endl;
    y=66;
    cout<<x;
    //TYPE CASTING
    float ab=25.99;
    cout<<endl<<"Value of ab is "<<int(ab);   //or we can write (int)ab;
    return 0;
}