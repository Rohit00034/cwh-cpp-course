//SAW AN EXAMPLE ABOUT THE VIRTUAL BASE CLASS TO AVOID AMBIGUITY
#include <iostream>
using namespace std;
/*
STUDENT-->TEST
STUDENT-->SPORTS
TEST-->RESULT
SPORTS-->RESULT
*/
class Student{
    protected:
    int roll_num;
    public:
    void set_rollnum(int r){
        roll_num=r;
    }
    void printrollnum(){
        cout<<"ROLL NUMBER IS : "<<roll_num<<endl;
    }
};
class Test : public virtual Student{   //we can alos write virtual public Student
protected:
int mathsmarks,physicsmarks;
public:
void set_marks(int mm,int pm){
    mathsmarks=mm;
    physicsmarks=pm;
}
void showmarks(){
    cout<<"MARKS IN MATHS : "<<mathsmarks<<endl<<"MARKS IN PHYSICS : "<<physicsmarks<<endl;
}
};
class Sports : virtual public Student{
protected:
int sportsmarks;
public:
void setsportsmarks(int s){
    sportsmarks=s;
}
void displaysports(){
    cout<<"MARKS IN SPORTS : "<<sportsmarks<<endl;
}
};
class Result : public Test,public Sports{
protected:
float total;
public:
void displayresult(void){
    total=mathsmarks+physicsmarks+sportsmarks;
    printrollnum(); //here we can see that we are not getting the ambiguity error due to virtual base class
    showmarks();
    displaysports();
    cout<<"YOUR TOTAL MARKS ARE : "<<total<<endl;
}
};
int main(){
    Result harryputter;
    harryputter.set_rollnum(40); //this is also not ambigous (its from base class)
    harryputter.set_marks(85,78);
    harryputter.setsportsmarks(9);
    harryputter.displayresult();
    return 0;
}