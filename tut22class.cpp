/*LEARNT ABOUT CLASSES AND HOW WE CAN HIDE/ABSTRACT THINGS AND KEEP THEM PRIVATE
(E.G chk_bin()function) using nesting of member functions*/
//you can format(not clear) your code/document by right clicking in vs code
#include <iostream>
using namespace std;
//we can declare objects with class definition
class Gamer{
//code
}obj1,obj2,obj3;
class Binarynum{
    private:
    void chk_bin(void);//we saved a lot of space here by just declaring the fucntion here
    string bn;
    public:
    void read(void); //read in comp means take input and write means give us output
//void chk_bin(void);//void here means it does'nt take any arguments
void onescompilment(void);
void displaybn();
};
void Binarynum:: read(){
cout<<"Enter a binary number: ";
cin>>bn;
}
void Binarynum:: chk_bin(){
for(int i=0;i<bn.length();i++){
    if(bn.at(i)!='1' && bn.at(i)!='0'){
        cout<<"Incorrect binary format";
        exit(1);// stops the program execution (gives error to system)
    }
}
}
void Binarynum:: onescompilment(){
    chk_bin(); //nesting member function
    for (int i = 0; i < bn.length(); i++)
    {
        if(bn.at(i)=='1'){ //here we cannot do comparison with "1" beacause double quote indicate a string but our string is made up of const char there single quote is used
            bn.at(i)='0';
        }
        else if(bn.at(i)=='0'){
            bn.at(i)='1';
        }   
    }
    
}
void Binarynum:: displaybn(){
    chk_bin(); //nesting member function
    cout<<"Your binary number is:\n";
    for (int i = 0; i < bn.length(); i++)
    {
        cout<<bn.at(i);
        
    }
    cout<<endl;
    
}
int main(){
    Binarynum b1;
    b1.read();
    //b1.chk_bin();  ..instead of this we used the fucntion as a nested function and this can't be used as it has become a private member function
    b1.displaybn();  
    b1.onescompilment();
    b1.displaybn();
    return 0;
}