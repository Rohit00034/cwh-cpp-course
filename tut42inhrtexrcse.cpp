//IMPLEMENTED A HYBRID CALULATOR CLASS USING MULTIPLE INHERITANCE 
/*
Create 2 classes:
1. SimpleCalculator Takes input of 2 numbers using a utility function and perfoms +,-,*, / 
and displays the results using another function.
2. ScientificCalculator Takes input of 2 numbers using a utility function and perfoms any 
four scientific operation of your chioice and displays the results using another function.
Create another class HybridCalculator and inherit it using these 2 classes:
Q1. What type of Inheritance are you using?
Q2. Which mode of Inheritance are you using?
Q3. Create an object of HybridCalculator and display results of simple and scientific 
calculator.
Q4. How is code reusability implemented?
*/
#include <iostream>
#include <cmath>
using namespace std;
//here we could have used template function rather than declaring functions for diff data types
class Simplecalc{
protected:
int num1,num2;
float numf1,numf2;
void inputnum();
void inputnumf();
public:
void add();
void addf();

void sub(void);
void subf(void);
void multiply(void);
void multiplyf(void);
void divide(void);
void dividef(void);

};
void Simplecalc :: inputnum(){
    cout<<"Enter fist number: \n";
    cin>>num1;
    cout<<"Enter second number: \n";
    cin>>num2;
}
void Simplecalc :: inputnumf(){
    cout<<"Enter fist number: \n";
    cin>>numf1;
    cout<<"Enter second number: \n";
    cin>>numf2;
}
void Simplecalc :: add(){
    inputnum();
    cout<<"Addition is : "<<num1+num2<<endl;
}
void Simplecalc :: addf(){
    inputnumf();
    cout<<"Addition is : "<<numf1+numf2<<endl;
}
void Simplecalc :: sub(){
    inputnum();
    cout<<"Substraction is : "<<num1-num2<<endl;
} 
void Simplecalc :: subf(){
    inputnumf();
    cout<<"Substraction is : "<<numf1-numf2<<endl;
} 
void Simplecalc ::multiply(){
    inputnum();
    cout<<"Multilplication result is : "<<num1*num2<<endl;
}
void Simplecalc ::multiplyf(){
    inputnumf();
    cout<<"Multilplication result is : "<<numf1*numf2<<endl;
}
void Simplecalc ::divide(){
    inputnum();
    cout<<"Divide result is : "<<num1/num2<<endl;
}
void Simplecalc ::dividef(){
    inputnumf();
    cout<<"Divide result is : "<<numf1/numf2<<endl;
}
class Scientificcalc /*: public Simplecalc*/{  /*here if i inherit simplecalc then again  
    inherit the simplecalc at the hybridcalc then all the functions in the simplecalc 
    will become ambigous that is we get copies of the simplecalc class one from inheriting 
     in the scientific and one from inheriting in the hybridcalc ,confusing the 
    compiler which one to use this can be resolved by ambiguity resolution whihc is in
    next tut*/
public:
    int factorial(int n);
 void square();
 void powerof();
 void sqrtof();
};
int Scientificcalc:: factorial(int n){
    
    if(n<=1){
        return 1;
    }
    return n*factorial(n-1);  //n!=n*(n-1)!
}
void Scientificcalc ::square(){
    int n;
    cout<<"Enter number to square: \n";
    cin>>n;
    cout<<"The square is: "<<n*n;

}
void Scientificcalc::powerof(){
    int n,times;
    cout<<"Enter the number: ";
    cin>>n;
    cout<<"\nEnter the power : ";
    cin>>times;
    int res=n;
    for(int i=1;i<times;i++){
        res=res*n;
    }
    cout<<n<<" power "<<times<<"is "<<res<<endl;
}
void Scientificcalc::sqrtof(){
    cout<<"Enter the number to get square root of : ";
    int n;
    cin>>n;
    cout<<"\nSquare root is :"<<sqrt(n)<<endl;
}
class Hybridcalc : public Simplecalc,public Scientificcalc{

};
int main(){
Hybridcalc calci;
while(1){
    int set=11;
    cout<<"Select from the options below: "<<endl;
    cout<<"1)add "<<endl;
    cout<<"2)sub "<<endl;
    cout<<"3)divide "<<endl;
    cout<<"4)multiply "<<endl;
    cout<<"5)factorial "<<endl;
    cout<<"6)square "<<endl;
    cout<<"7)powerof"<<endl;
    cout<<"8)sqrt"<<endl;
    cout<<"9)exit"<<endl;
    int choice;
    cin>>choice;
    switch(choice){
        
        case 1:
        cout<<"press 1 for integer and 2 for float \n";
        int choose1; cin>>choose1;
        if(choose1==1){
            calci.add();
        }
        else{
            calci.addf();
        }
        break;
        case 2:
        cout<<"press 1 for integer and 2 for float \n";
        int choose2; cin>>choose2;
        if(choose2==1){
            calci.sub();
        }
        else{
            calci.subf();
        }
        break;
        case 3:
        cout<<"press 1 for integer and 2 for float \n";
        int choose3; cin>>choose3;
        if(choose3==1){
            calci.divide();
        }
        else{
            calci.dividef();
        }
        break;
        case 4:
        cout<<"press 1 for integer and 2 for float \n";
        int choose4; cin>>choose4;
        if(choose4==1){
            calci.multiply();
        }
        else{
            calci.multiplyf();
        }
        break;
        case 5:
        int num;
        cout<<"Enter number for calculating factorial:";
        cin>>num;
        cout<<endl;
        cout<<"Factotrial is: "<<calci.factorial(num);
        break;
        case 6:
        calci.square();
        break;
        case 7:
        calci.powerof();
        break;
        case 8:
        calci.sqrtof();
        break;
        case 9:
        set=0;
        break;
    }
    if(set==0){
        break;
    }
}  
    return 0;
}