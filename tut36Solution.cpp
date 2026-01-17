#include <iostream>
using namespace std;
class child;
class parent{
    public:
void AccessChildData(child c1);
};
class child:protected parent{
protected:
public:
int a;

};
void parent :: AccessChildData(child c1){
    cout<<c1.a;
}
int main(){
    child c1;
    c1.a=22;
    parent p1;
    p1.AccessChildData(c1);
    return 0;
}