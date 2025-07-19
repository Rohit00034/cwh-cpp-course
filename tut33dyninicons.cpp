/*LEARNT ABOUT DYNAMIC INITIALIZATION OF OBJECTS (INITIALIZATION BASED ON USER INPUT)
AND SOME CONCEPTS RELATED TO CONSTRUCTOR OVERLOADING */
//REMEMBER THAT THE CLASS IS A DATA TYPE JUST LIKE INTEGER IN INT A=5;
#include <iostream>
using namespace std;
class Bankdeposit{
int principal;
int years;
float returnvalue;
float interestrate;
public:
Bankdeposit(){} /*default constructor| if we don't define the default constructor and make 
an object(like bd1 here) without passing any arguments then there will be an error, this is 
due to , when an object is created it searches for a constructor to call since we have 
overloaded the constructor it gets confused which one to use beacause there is no deafult 
construtor defined*/
Bankdeposit(int p,int y,int i){ //recommended to know the concept of simple and compound interest
    principal=p;
    years=y;
    interestrate=float(i)/100;
    returnvalue=principal;
    for(int i=0;i<y;i++){returnvalue=returnvalue*(1+interestrate);}
}
Bankdeposit(int p,int y,float i){
    principal=p;
    years=y;
    interestrate=i;
    returnvalue=principal;
    for(int i=0;i<y;i++){
        returnvalue=returnvalue*(1+interestrate);
    }
}
void show(){
    cout<<"The Principal amount was "<<principal<<" after "<<years<<" years "<<"the return is: "<<returnvalue<<endl;
}
};
int main(){
    Bankdeposit bd1,bd2,bd3 ;
    int p,y,ir;
float IR;
cout<<"Enter the principal value,years,interest rate(int):\n";
cin>>p>>y>>ir;
bd2=Bankdeposit(p,y,ir);//this works on int vakue of interestrate
bd2.show();
cout<<"Enter the principal value,years,interest rate(float):\n";
cin>>p>>y>>IR;
bd3=Bankdeposit(p,y,IR); //this works on float vakue of interestrate
bd3.show();
    return 0;
}