//A simple example ot friend function
#include <iostream>
using namespace std;
class Y; //if we don't give a forward declaration then in below add(X,Y) the X class does not know what Y is and it throws an error.
class X{
    int data;
    public:
    void setval(int value){
        data=value;
    }
    friend void add(X,Y); //the X,Y in add(X,Y) shows that the function accepts objects of X and Y classes respectively
};
class Y{
    int numY;
    public:
    void setval(int value){
        numY=value;
    }
    friend void add(X,Y); //the X,Y in add(X,Y) shows that the function accepts objects of X and Y classes respectively
};
void add(X o1,Y o2){
    cout<<"Sum of data of X and Y class are: "<<(o1.data+o2.numY);
}
int main(){
 X X1;
 Y Y1;
 X1.setval(2);   
 Y1.setval(4);  
 add(X1,Y1); //Sum of data of X and Y class are: 6
    return 0;
}