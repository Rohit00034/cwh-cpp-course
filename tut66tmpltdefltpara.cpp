//LEARNT ABOUT CLASS TEMPLATES WITH DEFAULT PARAMETERS
#include <iostream>
using namespace std;
//CLASS TEMPLATE WITH DEFAULT PARAMETERS
template <class T1=int,class T2=string> //TEMPLATE WITH DEFAULT PARAMETERS
class Printer{
public:
T1 data1;
T2 data2;
Printer(T1 d1,T2 d2 ){
    data1=d1;
    data2=d2;
}
void display(){
    cout<<"The value of data1 is: "<<data1<<endl;
    cout<<"The value of data2 is: "<<data2<<endl;
}
};
int main(){
    Printer<> obj1(1,"apple"); 
    obj1.display();
    cout<<endl;
    Printer obj2(3,"melon"); //can also use it like this
    obj2.display();
    cout<<endl;
    Printer<float,string> obj3(677.89,"rupees");
    obj3.display();
    return 0;
}