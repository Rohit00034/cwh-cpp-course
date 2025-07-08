/*learnt about basic arrays,traversing arrays,pointer and array(pointer arithmetic)
this is for an array,we can get the address of array by directly the arrayname and store it in pointer
without using the "&(addres of in terms of codewharry)" operator .to traverse thorugh array using pointer 
we can increment the pointer directly by one to shift the position of pointer array in the array by default it 
points to the first element of the array . We can also get the value of the array by dereferencing the pointer.
Formula for the address calculation of the ponter:-address(new)=address(old)+i*sizeof datatype*/ 
#include <iostream>
using namespace std;
int main(){
    int pts[]={1,34,34,234,4,546,45},a=0,b=0;
    while(a<sizeof(pts)/sizeof(pts[0])){
        cout<<pts[a]<<endl;
        a++;
    }
    cout<<"by do while"<<endl;    
    do{
        cout<<pts[b]<<endl;
        b++;
    }while(b<sizeof(pts)/sizeof(pts[0]));   //here works operator precedence
    //pointer and arrays
    int *pta=pts;
    cout<<"address of the first element is:"<<pta<<endl;  //getting the address of the first element of the array
    cout<<"value of the first element is:"<<*pta<<endl;  //getting the value at the first element of the array
    cout<<"address of the second element is:"<<(pta+1)<<endl;  //getting the address of the second element of the array
    cout<<"value of the second element is:"<<*(pta+1)<<endl;  //getting the value at the second element of the array
    //NOTE: ALWAYS USE PARENTHESIS WHEN USING THE PPOINTERS AS THE VALUE OF THE ARRAY IT SELF CAN BE MODIFIED
    //MODIFYING THE FIRST VALUE OF THE ARRAY
    cout<<"value of the first element is:"<<*pta+1<<endl;  //MODIFYING
    cout<<pts[0];                  /*we can also use the preincrement and postincrement operators with pointers
    which also changes the value of the pointer while dereferencing*/
    //USING THE ADDRESS CALCULATION FORMULA ADDRESS(NEW)=ADDRESS(OLD)+I*SIZEOF(ARR ELEMENTS/data type)
    int *newadd=pts+1*sizeof(pts[0]);  
    cout<<endl<<*newadd;


    return 0;
}