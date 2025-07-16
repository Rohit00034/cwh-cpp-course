//LEARNT ABOUT PARAMETERIZED CONSTRUCTOR 
/*this code has an example/implementation of a game event of recieving the correct item 
and this is given by mw now by cwh*/
#include <iostream>
#include <string>
using namespace std;
class RecieveItem{
    string item1,item2;
    void checkitem(){     //a private function to hide details (abstraction)
        if((item1=="emerald" and item2=="paper") or(item1=="paper" and item2=="emerald")){
            cout<<"Recieved correct items!! Here is your Book of mending I\n";
        }
        else{
            cout<<"WRONG ITEMS!! EHH\n";
        }
    }
    public:
    RecieveItem(string,string); //this is a parameterized constructor as it has 2 parameters
};
RecieveItem::RecieveItem(string a,string b){
    item1=a;
    item2=b;
    checkitem();  
}
string* takeitems(){  /*IGNORE THIS IF REVISING CONCEPTS,WHAT WE DID HERE IS USED A POINTER 
    TO THE START OF THE ARRAY BY ARRAY NAME AND RETURNED THAT POINTER,AND NOTE THAT THE 
    ARRAY HERE IS STATIC SO IT REMAINS EVEN AFTER THE FUNCTION ENDS,LATER WE USED THE POINTER
    TO ACCESS THE INFO IN THE ARRAY AND INCREMENTED IT TO ACCESS THE NEXT ELEMENT*/
    static string arr[2];
cout<<"Enter first item: ";
cin>>arr[0];
cout<<"Enter second item: ";
cin>>arr[1];
    return arr;  
}
int main(){
    string a,b;   
string *items=takeitems();    //POINTER ITEM=RETURNED POINTER
    a=*items; //DEREFERENCED POINTER
    b=*(items+1); //DEREFERENCED POINTER+1
//IMPLICIT CALL
RecieveItem trade(a,b);  //passing the value to the parameterized constructor
string* items2=takeitems();
a=*items2;
b=*(items2+1);
//EXPLICIT CALL
RecieveItem trade1=RecieveItem(a,b);
    return 0;
}