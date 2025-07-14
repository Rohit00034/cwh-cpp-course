//LEARNT about array of objects
#include <iostream>
using namespace std;
class Employee{
    int empid;
    int salary;
    static int counter;
public:
    void setid(){
salary=12000;
cout<<"\nEnter emp id: ";
cin>>empid;
counter++;
}
void getid(){
    cout<<"The id of employee is: "<<empid<<endl;
}
void displaynumemp(){
    cout<<"Number of employee in company are: "<<counter;
}
void countsetter(int a){
    a=counter;
}
};
int Employee :: counter;
int main(){
  Employee ig[4];  //array of objects where array data type is the class 
  int count=sizeof(ig)/sizeof(ig[0]);  //here we get 4 because the size is allocated as the arr of object is created
  
for (int i = 0; i <count ; i++)
{
   ig[i].setid();
   ig[i].getid();
   ig[i].displaynumemp();
}

    
    return 0;
}