/*LEARNT ABOUT CALL BY REFERENCE,CALL BY VALUE,CALL BY VALUE OF POINTERS(PASSING THE ADDRESS OF VARIABLES)
ALSO SAW HOW TO RETURN A REFERENCE VARAIBLE AND CHANGE THE VALUE OF ORIGINAL VARIBALE */
#include <iostream>
using namespace std;
void swap(int a,int b){  //passed by copy/value
    int temp=a;
    a=b;
    b=temp;
}
void swapwthptr(int *a,int *b){  //we create a pointer of type int whic stores address
/* 'a' is a ptr here*/    int temp =*a;  /*by using * we point the value at address stored
in a*/ 
    *a=*b;  //value at add a is = value at add b
    *b=temp;  //value at add b =temp
}
void swapreference(int &a /*here &a=x*/,int &b/*here &b=y*/){  /*using reference variables.when we use reference 
    varibles they point to the value at the address of the variable we are equaling to*/  
    int temp=a;
    a=b;
    b=temp;
}
//we can also return a reference variable in a fucntion
int & swaprefreturn(int &a /*here &a=x*/,int &b/*here &b=y*/){  /*using reference variables.when we use reference 
    varibles they point to the value at the address of the variable we are equaling to*/  
    int temp=a;
    a=b;
    b=temp;
    return a ; //a is value of x
}
int main(){
    int x=16,y=28;
    cout<<" value of a before swap "<<x<<" value of b before swap "<<y<<endl;
    swap(x,y);  //call by value (copies the value and passes it)
    cout<<" value of a after swap "<<x<<" value of b after swap "<<y<<endl; //we get no change
    swapwthptr(&x,&y);  //here we pass the addres of a and b to store in ptrs and use //CALL BY VAL OF PTRS  
    cout<<" value of a after swapwthptr "<<x<<" value of b after swapwthptr "<<y<<endl; //swapped
    swapreference(x,y);  //CALLED BY REFERENCE
    cout<<" value of a after swapref "<<x<<" value of b after swapref "<<y<<endl; //swapped
    swaprefreturn(x,y)=288;  //we just changed the value of x
    cout<<"value of x is "<<x; 
    return 0;
}