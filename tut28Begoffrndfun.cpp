//Simple example of friend function
#include <iostream>
using namespace std;
class c2; //forward declaration
class c1{
    int val1;
    public:
    void setval(int val){
        val1=val;
    }
    void displayval(){
        cout<<val1<<endl;
    }
    friend void exchange(c1 &,c2 &);
};
class c2{
    int val2;
    public:
    void setval(int val){
        val2=val;
    }
    void displayval(){
        cout<<val2<<endl;
    }
    friend void exchange(c1 &,c2 &);
};
void exchange(c1 & o1,c2 & o2){ //pass by reference to swap
    int tmp=o1.val1;
    o1.val1=o2.val2;
    o2.val2=tmp;
}
int main(){
    c1 obj1;
    c2 obj2;
    obj1.setval(29);
    obj2.setval(23);
    exchange(obj1,obj2);
    cout<<"Value of obj1 after exchange is: ";
    obj1.displayval();
    cout<<"Value of obj2 after exchange is: ";
    obj2.displayval();
    /*Value of obj1 after exchange is: 23
      Value of obj2 after exchange is: 29*/
    return 0;
}