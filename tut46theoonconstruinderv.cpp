/*LEARNT THEORY ABOUT CONSTRUCTOR IN DERIVED CLASS AND IT'S PRIORITIZATION AND IT'S 
CALLING SEQUENCE
REFER TO FOLDER FOR THEORY*/
//these below are my examples
#include <iostream>
using namespace std;
/*1)constructors in derived class*/
class Bapu{
    public:   //constructors are always public
Bapu(int a,int b){
    cout<<"Base classs constructor called!!\n";
    cout<<"a is "<<a<<" b is "<<b<<endl;  
    
}

};
class Beta : public Bapu{
    public:       //constructors are always public
    Beta(int a,int b):Bapu(a,b){
        cout<<"derived classs constructor called!!\n";
        
}
};

int main(){
//   Beta b1(2,3);  this won't work as there was no parametrized constructor in class Beta
//to pass values to the construtor of base class Bapu we can use the constructor of Beta
//now it will work
Beta b1(2,3);
    return 0;
}
//other concepts example in further tuts