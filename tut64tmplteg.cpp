//LEARNT ABOUOT TEMPLATES WITH AN EXAMPLE
#include <iostream>
using namespace std;
/*the example in vid is diff(uses the concept of vectors and dot product) and here it is simpler refer video for diff example
code is availabe here:- https://archive.codewithharry.com/videos/cpp-tutorials-in-hindi-64/ */
//MAKING A DATA TYPE FLEXIBLE CLASS TEMPLATE TO INPUT AND PRINT THE INPUT DATA
template <class T> //we can use anything instead of T and also note there is no ; here as it is at the end of the class
class Printer{
public:
Printer(T data){ 
    cout<<"Your data entered is: "<<data<<endl;
}
};

int main(){
    Printer <int> i1(3);
    Printer <float> f1(3.43f);
    Printer <char> c1('H');
    Printer <string> s1("this is template");
    return 0;
}
/*IN SHORT WE CAN DEFINE CLASSES FOR ANY DATA TYPE JUST LIKE FUNCTION OVERLOADING */