/*LEARNT ABOUT POINTER TO OBJECTS AND ARROW OPERATOR,CREATING OBJECTS DYNAMICALLY BY NEW 
KEYWORD*/
#include <iostream>
using namespace std;
class Complexnum{
int real,imaginary;
public:
void setdata(int a,int b){
real=a;
imaginary=b;
}
void getdata(){
    cout<<"Value of real part is: "<<real<<endl;
    cout<<"Value of imaginary part is: "<<imaginary<<endl;
}
};
int main(){
    // Complexnum c1; //noramal way of making an object
    // c1.setdata(2,3);//normal way of accessing object functions
    // c1.getdata();
    Complexnum *ptr=new Complexnum; /*dynamically created an object of class Complexnum,
    new keyword returns a pointer with address to an object in the memory,the ptr pointer is 
    equated to that pointer*/ 
    (*ptr).setdata(2,3);//new way of accessing the object functions
    (*ptr).getdata();
    //now another syntax to do the same is using the arrow -> operator
    ptr->setdata(2,5);
    ptr->getdata();
    //BOTH WAYS ARE THE SAME JUST DIFFERENT SYNTAX
    //creating array of objects dynamically
    Complexnum *ptrtoarr=new Complexnum[4];
    ptrtoarr->setdata(3,4);// or (*ptrtoarr).setdata(3,4);
    ptrtoarr->getdata();// or (*ptrtoarr).getdata(3,4);
    (ptrtoarr+1)->setdata(50,97);
    (ptrtoarr+1)->getdata();

    return 0;
}