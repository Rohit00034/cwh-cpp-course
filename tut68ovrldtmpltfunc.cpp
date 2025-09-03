/*LEARNT TO DEFINE MEMBER FUNCTION IN A TEMPLATE CLASS AND OVERLOADING A FUNCTION USING 
TEMPLATE*/
#include <iostream>
using namespace std;
template <class T>
class Bhodur{
public:
T data;
Bhodur(T d){
    data=d;
}
void display();

};
template <class T>
void Bhodur<T>::display(){
cout<<"Data is: "<<data<<endl;
}//defined member function of template class outside the class

//funtion overloading with template
void batao(int a){
    cout<<"I am "<<a<<" function()"<<endl;
}
template <class T> //overloaded batao function with T
void batao(T a){
    cout<<"I am templatized "<<a<<" function()"<<endl;
}

int main(){
    Bhodur obj1(2);
    Bhodur obj2('c');
    obj1.display();
    batao(2); /*here the 2 is int so the function defined for int will be called as it is a 
    perfect match*/
    batao(2.5);//here the templatized function is called
    batao("useless");//here the templatized function is called
    return 0;
}