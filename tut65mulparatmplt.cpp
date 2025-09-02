//LEARNT ABOUT TEMPLATE WITH MULTIPLE PARAMETERS
#include <iostream>
using namespace std;
//CLASS TEMPLATE WITH MULTIPLE PARAMETERS
template <class T1,class T2> //template with multiple parameters//can't do like <class T1,T2>
class PrintTwo{
public:
T1 data1;
T2 data2;
PrintTwo(T1 d1,T2 d2){
    data1=d1;
    data2=d2;
}
void display(){
    cout<<"VALUE OF DATA1 IS: "<<data1<<endl;
    cout<<"VALUE OF DATA2 IS: "<<data2<<endl;
}
};
int main(){
    PrintTwo<int,char> obj1(2,'H');
    obj1.display();
    PrintTwo<int,string> obj2(2,"Hello");
    obj2.display();
    return 0;
}